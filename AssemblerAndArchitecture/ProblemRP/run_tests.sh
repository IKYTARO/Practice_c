#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TESTS_DIR="${SCRIPT_DIR}/tests"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
PROGRAM="${PROJECT_ROOT}/problem_rp"

# Проверки
if [ ! -d "$TESTS_DIR" ]; then
    echo "❌ Error: 'ProblemRP/tests': no such directory"
    exit 1
fi

if [ ! -f "$PROGRAM" ]; then
    echo "❌ Error: '$PROGRAM': no such app"
    echo "   Use 'make problem_rp' for compile"
    exit 1
fi

# Создаем директорию для результатов
RESULTS_DIR="${PROJECT_ROOT}/test_results"
mkdir -p "$RESULTS_DIR"

echo "=== Start testing ==="

passed=0
failed=0

for dat_file in "$TESTS_DIR"/*.dat; do
    if [ ! -f "$dat_file" ]; then
        continue
    fi
    
    # Извлекаем номер теста из имени файла
    test_name=$(basename "$dat_file" .dat)
    ans_file="${TESTS_DIR}/${test_name}.ans"
    
    if [ ! -f "$ans_file" ]; then
        echo "⚠️  Test $test_name: missed (no .ans file)"
        continue
    fi
    
    # Выполняем тест
    result_file="${RESULTS_DIR}/${test_name}_result.txt"
    $PROGRAM < "$dat_file" > "$result_file"
    
    # Сравниваем результаты
    if diff -q "$result_file" "$ans_file" > /dev/null; then
        echo "✅ Test $test_name: PASSED"
        ((passed++))
    else
        echo "❌ Test $test_name: FAILED"
        echo "   Input: $(cat "$dat_file")"
        echo "   Correct output:"
        cat "$ans_file"
        echo ""
        echo "   Received output:"
        cat "$result_file"
        echo ""
        ((failed++))
    fi
done

rm -rf ${RESULTS_DIR}

total_tests=$((passed + failed))

echo
echo "=== Results ==="
echo "Passed: $((passed * 100 / total_tests))%"
echo "Failed: $((failed * 100 / total_tests))%"