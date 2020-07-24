#!/usr/bin/env sh

git pull origin master

echo "> pull complete"

git add .

echo "> add all files"

COMMIT_MESSAGE=${1}
git commit -m "${COMMIT_MESSAGE}"



echo "> commit complte"

git push origin HEAD:master

echo "> push complete"