#include<stdio.h>
#include "encode.h"
#include "types.h"
#include "decode.h"

#include <string.h>

int main(int argc, char *argv[])
{
    if(argc<4)
    {
        printf("Invalid arguments\n");
        printf("For encoding --> ./a.out -e beautiful.bmp secret.txt [stego.bmp]\n");
        printf("For decoding --> ./a.out -d stego.bmp output.txt\n");
        return e_failure;
    }

    if(check_operation_type(argv)==e_encode)
    {
        printf("You chosed encoding.\n");
        EncodeInfo encode;
        if(read_and_validate_encode_args(argv,&encode)==e_success)
        {
            printf("Read and validate is successful\n");
            
        }
        else
        {
            printf("Read and validate is unsuccessful\n");
            return e_failure;
        }
        if(do_encoding(&encode)==e_success)
        {
            printf("Encoding of the file is successful\n");
        }
        else
        {
            printf("File is not encoded\n");
            return e_failure;
        }
    }
    else if(check_operation_type(argv)==e_decode)
    {
        printf("You chosed decoding.\n");
        DecodeInfo decode;
        if(read_and_validate_decode_args(argv,&decode)==e_success)
        {
            printf("Read and validate is successful for decoding\n");
            
        }
        else
        {
            printf("Read and validate is unsuccessful for decoding\n");
            return e_failure;
        }
       
        if(do_decoding(&decode)==e_success)
        {
            printf("Decoding of the file is successful\n");
        }
        else
        {
            printf("File is not decoded\n");
            return e_failure;
        }
    }
    else
    {
        printf("You have chosed neither encoding nor decoding.");
    }
}


OperationType check_operation_type(char *argv[])
{
   if(strcmp(argv[1],"-e")==0)
   return e_encode;
   else if(strcmp(argv[1],"-d")==0)
   return e_decode;
   else
   return e_unsupported;
}