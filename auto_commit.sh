#!/bin/bash

REPO_PATH="/Users/jiyong/XcodeProjects/algorithm-study-cpp"
TODAY_DATE=$(date +'%Y-%m-%d')

cd "$REPO_PATH" || { echo "잘못된 경로: $REPO_PATH"; exit 1; }
CHANGED_FILES=$(git status --porcelain | awk '{print $2}' | grep '\.cpp$')

LOG_FILE="$REPO_PATH/commit_log.txt"

if [[ -z "$CHANGED_FILES" ]]; then
  echo "${TODAY_DATE}일 변경 사항이 없습니다. 종료합니다." >> "$LOG_FILE"
  exit 1
fi

PROBLEM_NUMBERS=$(echo "$CHANGED_FILES" | awk -F'/' '{print $1}')
PROBLEM_COUNT=$(echo "$PROBLEM_NUMBERS" | wc -l | tr -d '[:space]')
FIRST_PROBLEM=$(echo "$PROBLEM_NUMBERS" | head -n 1)

if [[ "$PROBLEM_COUNT" -eq 1 ]]; then
  COMMIT_MSG="[Add] ${TODAY_DATE} / ${FIRST_PROBLEM}번 문제 풀이"
else
  COMMIT_MSG="[Add] ${TODAY_DATE} / ${FIRST_PROBLEM}번 등 ${PROBLEM_COUNT}개 문제 풀이"
fi

echo "오늘자 커밋 메시지: $COMMIT_MSG" >> "$LOG_FILE"

git add .

if git commit -m "$COMMIT_MSG"; then
  echo "✅ 커밋 성공: $COMMIT_MSG" >> "$LOG_FILE"
else
  echo "❌ 커밋 실패" >> "$LOG_FILE"
  exit 1
fi

if git push origin main; then
  echo "✅ 푸시 성공" >> "$LOG_FILE"
else
  echo "❌ 푸시 실패" >> "$LOG_FILE"
  exit 1
fi

echo "$TODAY_DATE일 알고리즘 문제 커밋 완료." >> "$LOG_FILE"
