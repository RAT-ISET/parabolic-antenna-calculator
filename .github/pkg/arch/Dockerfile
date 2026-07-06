FROM archlinux:latest
LABEL authors="Rangeset"

CMD ["/bin/bash"]

RUN pacman -Syu --noconfirm && pacman -S --noconfirm base-devel && useradd -m builder

USER builder
WORKDIR /home/builder
