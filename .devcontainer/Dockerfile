# ベースとなるOS（Ubuntuの最新LTS）
FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-24.04

# 追加で必要なツールがあればここでインストール
# 競技プログラミング用に最新のGCCやツールを入れる
RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    git \
    && apt-get clean
RUN apt-get update && apt-get install -y nodejs npm python3-pip python3-venv
RUN npm install -g atcoder-cli
# venvを使用してojをインストール
RUN python3 -m venv /opt/venv
ENV PATH="/opt/venv/bin:$PATH"
RUN pip3 install online-judge-tools