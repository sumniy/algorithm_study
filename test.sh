#!/usr/bin/env sh


REMOTE_REPO=$(git remote)

echo "$REMOTE_REPO"

echo "$(git remote show $REMOTE_REPO)"

BRANCH=$(git branch)

echo "$BRANCH"