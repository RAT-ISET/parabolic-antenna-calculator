FROM archlinux:latest
LABEL authors="Rangeset"

CMD ["/bin/bash"]

RUN pacman -Syu --noconfirm && pacman -S --noconfirm base-devel && useradd -m builder

USER builder
WORKDIR /home/builder

COPY --chown=builder:builder tmp/ ./

RUN bash pkg.sh

FROM scratch AS exporter
COPY --from=0 /home/builder/*.pkg.tar.zst /
