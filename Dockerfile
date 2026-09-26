# Dockerfile

#   SPDX-License-Identifier: MIT
#   Copyright (c) 2026 Nico Erdmann
#   Dockerfile for NC

FROM gcc:latest AS builder

RUN apt-get update && apt-get install -y \
    cmake \
    make \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
COPY . .

RUN mkdir -p build && cd build \
    && cmake .. \
    && cmake --build .

RUN bash -c 'for test in tests/**/*.c; do ./TEST.sh "$test"; done'