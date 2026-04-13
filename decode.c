#include<stdio.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"
#include <string.h>

Status read_and_validate_decode_args(char *argv[], DecodeInfo *dencInfo)
{
    if(strstr (argv[2],".bmp")!=NULL)
    {
        dencInfo->stego_image_fname=argv[2];

    }
    else
    {
        printf(".bmp file is not found in the command\n");
        return e_failure;
    }
    if(strstr (argv[3],".txt")!=NULL)
    {
        dencInfo->output_image_fname=argv[3];
    }

   
    
    dencInfo->output_image_fname="output.txt";
     
    return e_success;
}

Status do_decoding(DecodeInfo *decInfo)
{
    if(open_files_decode(decInfo)==e_success)
    {
        printf("All files are open now . ready to decode\n");
    }
    else
    {
        printf("Files not opened. not ready to decode\n");
        return e_failure;
    }
      
    
    //Skip first 54 bits
    fseek(decInfo->fptr_stego_image, 54, SEEK_SET);

    if(decode_magic_string(decInfo)==e_success)
    {
        printf("Magic String decoded sucessfully and is validated\n");
    }
    else
    {
         printf("Magic String not decoded sucessfully\n");
    }

    if(decode_secret_file_extn_size(decInfo)==e_success)
    {
        printf("Secret file extension decoded succesfully !\n");
    }
    else
    {
        printf("Secret file extension not decoded succesfully\n");
    }

    //decode secret file size

    
    //decode secret file extension

    if(decode_secret_file_extn(decInfo)==e_success)
    {
         printf("Secret file extension is decoded sucessfully !\n");
    }
    else
    {
        printf("Error ! Secret file extension is not  decoded.\n");
        return e_failure;
    }

    decInfo->size_secret_file=decode_size_from_lsb(decInfo->fptr_stego_image);
    printf("Secret file size is %ld\n",decInfo->size_secret_file);

    if(decode_secret_file_data(decInfo)==e_success)
    {
        printf("Message is decoded sucessfully !\n");
    }
    else
    {
        printf("Message is not decoded\n");
        return e_failure;
    }


    return e_success;
}

Status open_files_decode( DecodeInfo *decInfo)
{
     if(open_stego_file(decInfo)==e_failure)
     {
        printf("Error: Unable to open stego file image \n");
        return e_failure;
     }
     decInfo->fptr_secret=fopen(decInfo->output_image_fname,"w");
     if(decInfo->fptr_secret==NULL)
     {
        printf("Error : Unable to open output file\n");
        return e_failure;
     }
    return e_success;
}

Status open_stego_file(DecodeInfo *decInfo)
{
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "rb");
    if (decInfo->fptr_stego_image == NULL)
        return e_failure;
    return e_success;
}

Status decode_magic_string(DecodeInfo *decInfo)
{
    char buffer[8];
    char magic_str[10]={0};
    int len=strlen(MAGIC_STRING);
    for(int i=0;i<len;i++)
    {
        fread(buffer,8,1,decInfo->fptr_stego_image);
        magic_str[i]=decode_byte_from_lsb(buffer);
    }

    if(strncmp(magic_str,MAGIC_STRING,len)==0)
    {
        // printf("The magic String is %s\n",magic_str);
        return e_success;
    }
    else
    return e_failure;
}

char decode_byte_from_lsb(char *buffer)
{
    char ch=0;
    for(int i=0;i<8;i++)
    {
        ch=ch|((buffer[i]&1)<<i);
    }
    return ch;

}

Status decode_secret_file_extn_size(DecodeInfo *decInfo)
{
    char buffer[32];
    fread(buffer, 32, 1, decInfo->fptr_stego_image);

    int size = 0;
    for (int i = 0; i < 32; i++)
    {
        size |= ((buffer[i] & 1) << i);
    }

    decInfo->extn_size = size;   // store in struct
    return e_success;
}

Status decode_size_from_lsb(FILE *fptr_stego)
{
    char buffer[32];
    fread(buffer,32,1,fptr_stego);

    int size=0;
    for(int i=0;i<32;i++)
    {
        size=size |((buffer[i]&1)<<i);
    }
    return size;
}



Status decode_secret_file_extn(DecodeInfo *decInfo)
{
    char buffer[8];
    for(int i=0;i<decInfo->extn_size;i++)
    {
        fread(buffer,8,1,decInfo->fptr_stego_image);
        decInfo->extn_secret_file[i]=decode_byte_from_lsb(buffer);
    }
    decInfo->extn_secret_file[decInfo->extn_size]='\0';
    printf("Extension of secret file is %s\n",decInfo->extn_secret_file);
    return e_success;

}


Status decode_secret_file_data(DecodeInfo *decInfo)
{
    char buffer[8];
    for(int i=0;i<decInfo->size_secret_file;i++)
    {
        fread(buffer,8,1,decInfo->fptr_stego_image);
        char ch=decode_byte_from_lsb(buffer);
        fwrite(&ch,1,1,decInfo->fptr_secret);
        printf("%c", ch);  
        fflush(stdout);
    }
     printf("\n");  // add a newline after printing the message
    return e_success;
}