FROM ps2dev/ps2toolchain-ee:latest

RUN apk add --no-cache build-base make gmp mpc1 mpfr readline-dev bash git tree cdrkit p7zip nano
RUN echo 'alias ll="ls -la"' >> /etc/bash/bashrc
