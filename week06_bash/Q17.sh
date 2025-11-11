#!/bin/bash

file_wordcnt() {

for file in *.txt
do
if [ -f "$file" ]; then
count=$(wc -w < "$file")

echo "$file 파일의 단어는 ${count} 개 입니다."
fi
done
}

file_wordcnt
