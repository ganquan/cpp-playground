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
    clang-format 



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

#install ohmyzsh
RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.5/zsh-in-docker.sh)" -- \
    -p git \
    -p autojump \
    -p https://github.com/zsh-users/zsh-autosuggestions \
    -p https://github.com/zsh-users/zsh-completions \
    -p https://github.com/zsh-users/zsh-syntax-highlighting \
    -a 'bindkey "\$terminfo[kcuu1]" history-substring-search-up' \
    -a 'bindkey "\$terminfo[kcud1]" history-substring-search-down' \
    -a 'alias vv="nvim"'


#install mlpack
RUN apt-get -y install \
    libarmadillo-dev \
    libcereal-dev \
    binutils-dev \
    libensmallen-dev \
    libstb-dev && \
    cd ${HOME} && \
     wget --no-check-certificate --quiet \
         http://mlpack.org/files/mlpack-4.3.0.tar.gz && \
         tar xzf ./mlpack-4.3.0.tar.gz && \
         cd mlpack-4.3.0 && \
         mkdir build && \
         cd build && \
         cmake .. && \
         make -j $(nproc) && \
         make install && \
         cd .. && \
         rm -rf ./mlpack-4.3.0

# start zsh
CMD [ "zsh" ]
