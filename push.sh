#!/usr/bin/env sh

git pull origin master

echo "> pull complete"

git add .

echo "> add all files"

if [ $# = 0 ]; then
  read -p "> enter commit message : " COMMIT_MESSAGE
else 
  COMMIT_MESSAGE=${1}
fi

git commit -m "${COMMIT_MESSAGE}"

echo "> commit complte"

git push origin HEAD:master

echo "> push complete"