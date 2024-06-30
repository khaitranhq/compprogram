FROM mcr.microsoft.com/devcontainers/base:1.0.12-debian12

RUN apt update && apt install curl git -y
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y
