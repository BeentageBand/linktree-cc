MONGOUSER=${MONGODB_USER:?MONGODB_USER not defined}
MONGOPASS=${MONGODB_USER:?MONGODB_PASS not defined}
PREFIX=linktree
HOST_PATH=$(realpath .)
HOST_PORT=8080

TARGET_PATH=/usr/src/linktree-cc
TARGET_PORT=8080
MONGODB_DB=contactlist
MONGODB_URI="mongodb+srv://${MONGODB_USER}:${MONGODB_PASS}@cluster0.lcfyt.mongodb.net/${MONGODB_DB}?retryWrites=true&w=majority"
