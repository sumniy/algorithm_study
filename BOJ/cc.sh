#!/usr/bin/env sh

PATH=$(pwd)
TARGET_DIR=$PATH${1}

echo ${TARGET_DIR}



# REMOTE_REPO=$(git remote)
# WORKING_BRANCH=$(git branch --show-current)

# git pull ${REMOTE_REPO} ${WORKING_BRANCH}

# echo "> pull complete from remote:${REMOTE_REPO} branch:${WORKING_BRANCH}"

# git add .

# echo "> add all files"

# if [ $# -eq 0 ]; then
#   read -p "> enter commit message : " COMMIT_MESSAGE
# else 
#   COMMIT_MESSAGE=${1}
# fi

# git commit -m "${COMMIT_MESSAGE}"

# echo "> commit complte"

# git push ${REMOTE_REPO} HEAD:${WORKING_BRANCH}

# if [ $? = 0 ]; then
#   echo "> push complete to remote:${REMOTE_REPO} branch:${WORKING_BRANCH}"
# else
#   git reset --soft HEAD^
#   echo "> push faild. please check the git error message."
# fi
