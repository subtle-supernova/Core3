### What are we doing?

Killin time. Having fun. Learning new stuff.

### Build instructions

These are for bare metal Debian 8.7 and they're pretty rough.

- Download oracle berkley DB from http://download.oracle.com/berkeley-db/db-5.3.28.tar.gz
  - `cd build/unix`
  - `./configure`
  - `make && make install`
  - You must not build this using clang, it hates it.
- Install lua5.2, 5.1, and 5.3 and headers (yep, all of them)
- move the `MMOEngine` dir into the `Core3` dir
- install build-essential clang openjdk-8-jdk mysql-server lua5.3 liblua5.3-dev liblua5.1-dev libmysqld-dev lipssl-dev
  - at the time of this writing, you need jessie-backports to install openjdk8
- you need a few flags set in your `~/.bashrc`
- `make config`
- edit `unix/build/src/Makefile` and where it adds `-llua` you'll need to link to lua5.1, 5.2, and 5.3
  - To do this, move `liblua5.1.so` to `/usr/local/lib`
- make sure the environment variables below are set in `$HOME/.bashrc`
- move all lua 5.2 header files to `/usr/local/include/`


Env vars:
```bash
export CC=clang
export CXX=clang++
export CPPFLAGS="-w -g -lstdc++ -DGTEST_USE_OWN_TR1_TUPLE=1 -I/usr/local/include"
export CXXFLAGS="-lstdc++ -stdlib=libstdc++"
export CLASSPATH="$HOME/PublicEngine/MMOEngine/bin/idlc.jar"

export PATH=$PATH:$HOME/PublicEngine/MMOEngine/bin
```
