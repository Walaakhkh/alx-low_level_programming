#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_elf_header(const Elf64_Ehdr *header);
void print_error(const char *message);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename\n");
        exit(98);
    }

    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error("Error: Unable to open file\n");
        exit(98);
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header)) {
        print_error("Error: Unable to read ELF header\n");
        close(fd);
        exit(98);
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3) {
        print_error("Error: Not an ELF file\n");
        close(fd);
        exit(98);
    }

    print_elf_header(&header);

    close(fd);
    return 0;
}

void print_elf_header(const Elf64_Ehdr *header) {
    printf("ELF Header:\n");
    printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x\n",
           header->e_ident[EI_MAG0], header->e_ident[EI_MAG1],
           header->e_ident[EI_MAG2], header->e_ident[EI_MAG3],
           header->e_ident[EI_CLASS], header->e_ident[EI_DATA],
           header->e_ident[EI_VERSION], header->e_ident[EI_OSABI]);
    printf("  Class:                             ");
    if (header->e_ident[EI_CLASS] == ELFCLASS32)
        printf("ELF32\n");
    else if (header->e_ident[EI_CLASS] == ELFCLASS64)
        printf("ELF64\n");
    else
        printf("<unknown: %02x>\n", header->e_ident[EI_CLASS]);

    printf("  Data:                              ");
    if (header->e_ident[EI_DATA] == ELFDATA2LSB)
        printf("2's complement, little endian\n");
    else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
        printf("2's complement, big endian\n");
    else
        printf("<unknown: %02x>\n", header->e_ident[EI_DATA]);

    printf("  Version:                           ");
    if (header->e_ident[EI_VERSION] == EV_CURRENT)
        printf("1 (current)\n");
    else
        printf("<unknown: %02x>\n", header->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_AIX: printf("UNIX - AIX\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_MODESTO: printf("UNIX - Modesto\n"); break;
        default: printf("<unknown: %02x>\n", header->e_ident[EI_OSABI]);
    }

    printf("  ABI Version:                       %u\n", header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (header->e_type) {
        case ET_NONE: printf("NONE (Unknown type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown: %02x>\n", header->e_type);
    }

    printf("  Entry point address:               0x%lx\n", header->e_entry);
}

void print_error(const char *message) {
    fprintf(stderr, "%s", message);
}
