print_param() {
echo "스크립트 이름 : $0"
echo "첫 번째 파라미터 : $1"
echo "두 번째 파라미터 : $2"
echo "모든 파라미터 : $*"
echo "파라미터의 개수 : $#"
}

print_param "Hello" "Word" "!"
