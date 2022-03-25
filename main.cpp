#define _GNU_SOURCE
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

// dummy cookie
class cookie {
public:
    int64_t offset = 0;

    cookie(){
        //
    }

    FILE* open();

    static ssize_t cookie_read(void* cookie, char* buf, size_t size);

    static ssize_t cookie_write(void* cookie, const char* buf, size_t size);

    static int cookie_seek(void* cookie, int64_t* offset, int whence);

    static int cookie_close(void* cookie);
};

FILE* cookie::open() {
    std::string mode("r+");
    const cookie_io_functions_t io_hooks = {
        cookie::cookie_read,
        cookie::cookie_write,
        cookie::cookie_seek,
        cookie::cookie_close,
    };
    return fopencookie(this, mode.c_str(), io_hooks);
}

ssize_t cookie::cookie_write(void *c, const char *buf, size_t size) {
    ssize_t writeBytes = 0;
    return writeBytes;
}

ssize_t cookie::cookie_read(void *c, char *buf, size_t size) {
    ssize_t readBytes = 0;
    return readBytes;
}

int cookie::cookie_seek(void *c, off64_t *offset, int whence) {
    if (whence == SEEK_CUR) {
        cookie* d = (cookie*)c;
        d->offset += *offset;
    }

    return 0;
}

int cookie::cookie_close(void *c) {
    return 0;
}

int main(int argc, char *argv[]) {
    cookie c;
    FILE* f = c.open();
    int pos = fseek(f, 10015, SEEK_CUR);
    return pos;
}