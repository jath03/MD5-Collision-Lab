#include <curl/curl.h>
#include <curl/easy.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char URL[480] = "https://raw.githubusercontent.com/jath03/MD5-Collision-Lab/refs/heads/main/download-";

char VERSION_HASH[128] = {0x11, [127]=0x11};

char hex_chars[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

int main()
{
  int i;
  char b;
  int l = strlen(URL);
  for (i=0; i<128; i++){
    //printf("%x", VERSION_HASH[i]);
    b = VERSION_HASH[i];
    URL[l + 0 + 2 * i] = hex_chars[(b & 0xF0) >> 4];
    URL[l + 1 + 2 * i] = hex_chars[(b & 0x0F) >> 0];
  }
  printf("%s\n", URL);

  CURL *curl = curl_easy_init();

  if (curl) {
    CURLcode res;

    curl_easy_setopt(curl, CURLOPT_URL, URL);

    FILE* file = fopen("my_software.sh", "w");

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    fclose(file);
  } else {
    printf("Error initializing curl");
  }

  system("./my_software.sh");

}
