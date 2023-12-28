FROM ubuntu:latest
LABEL Description="Build Dev Environment"

ENV HOME /root

SHELL ["/bin/bash", "-c"]

# ca-certificates   # 访问github.com需要校验证书
# build-essential   # debian基础的开发包
# clangd            # nvim lsp
# clang             # compiler
# cmake             # build tool
# wget              # for download
# git               # scm tool
# ninja-build       # build tool
# gettext           # build nvim dependency
# unzip             # for build nvim
# autojump          # for ohmyzsh plugin
# zsh               # for ohmyzsh
# clang-format

RUN apt-get update && apt-get upgrade -y && apt-get -y --no-install-recommends install \
    ca-certificates \
    build-essential \
    clangd \
    clang \
    cmake \
    wget \
    git \
    ninja-build \
    gettext \
    unzip \
    autojump \
    zsh \
    clang-format \
    libmlpack-dev \
    mlpack-bin \
    libarmadillo-dev



#install neovim
RUN cd ${HOME} && \
    wget --no-check-certificate --quiet \
        https://github.com/neovim/neovim/archive/refs/tags/v0.9.4.tar.gz && \
        tar xzf ./v0.9.4.tar.gz && \
        cd ./neovim-0.9.4 && \
        make CMAKE_BUILD_TYPE=RelWithDebInfo && \
        make install && \
        cd .. && \
        rm -rf ./neovim-0.9.4 && \
        rm v0.9.4.tar.gz && \
        cd ${HOME} && \
        mkdir .config && \
        cd ${HOME}/.config && \
        git clone https://github.com/ganquan/neovim-config.git nvim

# Let us add some heavy dependency
# RUN cd ${HOME} && \
#     wget --no-check-certificate --quiet \
#         https://boostorg.jfrog.io/artifactory/main/release/1.77.0/source/boost_1_77_0.tar.gz && \
#         tar xzf ./boost_1_77_0.tar.gz && \
#         cd ./boost_1_77_0 && \
#         ./bootstrap.sh && \
#         ./b2 install && \
#         cd .. && \
#         rm -rf ./boost_1_77_0

RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.5/zsh-in-docker.sh)" -- \
    -p git \
    -p autojump \
    -p ssh-agent \
    -p https://github.com/zsh-users/zsh-autosuggestions \
    -p https://github.com/zsh-users/zsh-completions \
    -p https://github.com/zsh-users/zsh-syntax-highlighting \
    -a 'bindkey "\$terminfo[kcuu1]" history-substring-search-up' \
    -a 'bindkey "\$terminfo[kcud1]" history-substring-search-down' \
    -a 'alias vv="nvim"'


# install cereal
# RUN cd ${HOME} && \
#      wget --no-check-certificate --quiet \
#          https://github.com/USCiLab/cereal/archive/refs/tags/v1.3.2.tar.gz && \
#          tar xzf ./v1.3.2.tar.gz && \
#          cd ./cereal-1.3.2/include && \
#          cp -r cereal /usr/local/include/ && \
#          cd ../.. && \
#          rm -rf ./cereal-1.3.2

# start zsh
CMD [ "zsh" ]
