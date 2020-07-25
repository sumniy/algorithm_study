#!/usr/bin/env sh


git remote show origin

if [ $? = 0 ]; then
  echo "> remote show success"
else
  echo "> remote show failed"
fi