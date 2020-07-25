#!/usr/bin/env sh

# pull, add, commit, push 각 과정이 실패했을 때를 핸들링해주고
# 현재 작업하는 remote가 어떤 지 알아내고, 브랜치를 알아내고 그 브랜치에 push 하도록
# 충돌 발생 시 중간에 멈춰주는 것도 하고,
# 그담에 만약에 add하고 commit할 때 에러나면 add 했던 거 취소도 해주고 그렇게 구현하자

REMOTE_REPO=$(git remote)
WORKING_BRANCH=$(git branch --show-current)

git pull ${REMOTE_REPO} ${WORKING_BRANCH}

echo "> pull complete from remote:${REMOTE_REPO} branch:${WORKING_BRANCH}"

git add .

echo "> add all files"

# push.sh 실행 시 매개변수를 전달하지 않으면 입력받고, 전달받으면 바로 COMMIT_MESSAGE에 저장한다.
if [ $# -eq 0 ]; then
  # read에 -p 옵션을 주면 입력한 프롬프트를 띄우고 입력을 대기한다.
  read -p "> enter commit message : " COMMIT_MESSAGE
else 
  COMMIT_MESSAGE=${1}
fi

git commit -m "${COMMIT_MESSAGE}"

echo "> commit complte"

git push ${REMOTE_REPO} HEAD:${WORKING_BRANCH}

if [ $? = 0 ]; then
  echo "> push complete to remote:${REMOTE_REPO} branch:${WORKING_BRANCH}""
else
  echo "> push faild. please check the git error message."
fi

# echo "> push complete to remote:${REMOTE_REPO} branch:${WORKING_BRANCH}"