#!/bin/bash

RED="\033[31m"
GREEN="\033[32m"
NC="\033[0m"

if [ -z "$1" ]; then
	echo "ERROR: bin does not specified..."
	exit 1
fi

BIN=$1
./${BIN}
RET=$?
if [ "${RET}" == "0" ]; then
	echo -e "${GREEN}OK${NC}"
else
	echo -e "${RED}KO${NC}"
fi
exit ${RET}
