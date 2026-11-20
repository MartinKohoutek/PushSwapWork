#!/bin/bash

set -o pipefail

MODE="Adaptive Test"
PS_OPTION=()

case "$1" in
    -s)
        MODE="Simple Test"
        PS_OPTION=(--simple)
        shift
        ;;
    -m)
        MODE="Medium Test"
        PS_OPTION=(--medium)
        shift
        ;;
    -c)
        MODE="Complex Test"
        PS_OPTION=(--complex)
        shift
        ;;
esac

if [ "$#" -ne 2 ] || ! [[ "$1" =~ ^[0-9]+$ ]] || ! [[ "$2" =~ ^[0-9]+$ ]]; then
    echo "Usage: $0 [-s|-m|-c] <size> <test_count>"
    exit 1
fi

SIZE=$1
TEST_COUNT=$2

if [ "$SIZE" -lt 2 ] || [ "$TEST_COUNT" -lt 1 ] || [ "$TEST_COUNT" -gt 100 ]; then
    echo "Size must be >= 2 and test_count must be between 1 and 100."
    exit 1
fi

if [ ! -x ./push_swap ]; then
    echo "Error: ./push_swap not found or not executable."
    exit 1
fi

targets=(0.05 0.15 0.25 0.35 0.45 0.55 0.65 0.75 0.85 0.95)

seeds=(
    14931 27843 9199 31670 16965 22321 29347 9024 31377 1455
    32216 18393 23095 20909 12260 1833 19324 24791 8408 19364
    9455 11076 21819 6243 4220 30253 30029 27590 9715 5750
    20386 11757 7909 4025 12692 31413 14239 7075 6436 2394
    28140 22902 16021 11025 22873 6251 22129 30047 5843 3307
    29446 11141 3416 10165 28455 31097 195 13240 21023 2038
    18126 29020 9641 2351 8805 23251 31435 16546 4697 21397
    25299 2775 31683 30056 3195 29180 20060 18138 25760 12641
    20888 17649 7205 30403 10503 21757 8154 21105 17348 25653
    20412 30879 3516 18563 931 10206 5153 27346 27982 14465
)

generate_with_disorder() {
    local size=$1
    local target=$2

    local arr=($(seq 1 "$size"))
    local total_pairs=$(( size * (size - 1) / 2 ))
    local target_inversions
    target_inversions=$(awk "BEGIN { printf \"%d\", int($target * $total_pairs) }")

    if [ "$target_inversions" -le 0 ]; then
        echo "${arr[@]}"
        return
    fi

    local current_inv=0
    local max_passes=$(( target_inversions * 4 + size * 2 ))

    for (( pass=0; pass<max_passes && current_inv<target_inversions; pass++ )); do
        local i=$(( RANDOM % (size - 1) ))
        local next=$(( i + 1 ))

        if [ "${arr[$i]}" -lt "${arr[$next]}" ]; then
            local tmp=${arr[$i]}
            arr[$i]=${arr[$next]}
            arr[$next]=$tmp
            current_inv=$(( current_inv + 1 ))
        fi
    done

    echo "${arr[@]}"
}

run_benchmark() {
    local dir=$1
    local -a sums=()
    local -a counts=()
    local total_ops=0
    local i rank seed_index seed permutation ops average
    local -a values

    for (( i=0; i<TEST_COUNT; i++ )); do
        rank=$(( i % 10 ))
        seed_index=$(( rank * 10 + i / 10 ))
        seed=${seeds[$seed_index]}

        permutation=$( ( RANDOM=$seed; generate_with_disorder "$SIZE" "${targets[$rank]}" ) )
        read -r -a values <<< "$permutation"

        ops=$( (cd "$dir" && ./push_swap "${PS_OPTION[@]}" "${values[@]}") | awk 'END { print NR }')

        sums[$rank]=$(( ${sums[$rank]:-0} + ops ))
        counts[$rank]=$(( ${counts[$rank]:-0} + 1 ))
        total_ops=$(( total_ops + ops ))
    done

    for (( rank=0; rank<10; rank++ )); do
        if [ "${counts[$rank]:-0}" -gt 0 ]; then
            avg=$(awk "BEGIN { printf \"%.2f\", ${sums[$rank]} / ${counts[$rank]} }")
        else
            avg="0.00"
        fi
        printf "%s\t" "$avg"
    done

    average=$(awk "BEGIN { printf \"%.2f\", $total_ops / $TEST_COUNT }")
    printf "%s\n" "$average"
}

for dir in */; do
    if [ -x "$dir/push_swap" ]; then
        printf "%s\t" "${dir%/}"
        run_benchmark "$dir"
    fi
done