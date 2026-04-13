#ifndef DECODE_H
#define DECODE_H

#include <stdio.h>
#include "types.h"

typedef struct _DecodeInfo
{
    char *stego_image_fname;   // input stego file
    FILE *fptr_stego_image;    // stego image ptr
    FILE *fptr_secret;         // output secret file
    char *output_image_fname;
    char extn_secret_file[10]; // secret file extension
    int extn_size;             // extension size
    long size_secret_file;     // secret file size
} DecodeInfo;

// Main function
// Status do_decoding(DecodeInfo *decInfo);
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);
Status open_files_decode( DecodeInfo *decInfo);
Status do_decoding(DecodeInfo *decInfo);
Status open_stego_file(DecodeInfo *decInfo);
Status decode_magic_string(DecodeInfo *decInfo);
Status decode_data_from_image(char *data, int size, FILE *fptr_stego);
char decode_byte_from_lsb(char *buffer);
Status decode_size_from_lsb(FILE *fptr_stego);
Status decode_secret_file_extn(DecodeInfo *decInfo);
Status decode_secret_file_extn_size(DecodeInfo *decInfo);
Status decode_secret_file_size(DecodeInfo *decInfo);
Status decode_secret_file_data(DecodeInfo *decInfo);

#endif
