/*
 * File:
 *  curl_dl.c
 * Description:
 *   Dynamically load the curl library at runtime.
 * Author:
 *  Michael Andrews <mjands@gmail.com>
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include <curl/curl.h>

int curl(){
    void *handle;

    static CURL *(*f_init)(void) = NULL;
    static CURLcode (*f_setopt)(CURL *, CURLoption, ...) = NULL;
    static CURLcode (*f_perform)(CURL *) = NULL;
#if 0
    static CURLcode (*f_getinfo)(CURL *, CURLINFO, ...) = NULL;
#endif
    static void (*f_cleanup)(CURL *) = NULL;

    CURL *curl;
    CURLcode res;

    char *error;
    int i = 1000;

    printf("ok %d\n", i);
   /* handle = dlopen ("libcurl.so.3", RTLD_LAZY);

    printf("ok %d\n", i);
    if (!handle) {
        fprintf (stderr, "%s\n", dlerror());
        exit(1);
    }

    dlerror();
/*
    if ((error = dlerror()) != NULL)  {
        fprintf (stderr, "%s\n", error);
        exit(1);
    }*/

    printf("ok %d\n", i);
/*
    f_init = dlsym(handle, "curl_easy_init");
    if ((error = dlerror()) != NULL)  {
        fprintf (stderr, "%s\n", error);
        exit(1);
    }

    f_setopt = dlsym(handle, "curl_easy_setopt");
    if ((error = dlerror()) != NULL)  {
        fprintf (stderr, "%s\n", error);
        exit(1);
    }

    f_perform = dlsym(handle, "curl_easy_perform");
    if ((error = dlerror()) != NULL)  {
        fprintf (stderr, "%s\n", error);
        exit(1);
    }

    f_cleanup = dlsym(handle, "curl_easy_cleanup");
    if ((error = dlerror()) != NULL)  {
        fprintf (stderr, "%s\n", error);
        exit(1);
    }
*/
    printf("ok %d\n", i);

    curl = (*f_init)();

    if (curl) {
       (*f_setopt)(curl, CURLOPT_URL, "curl.haxx.se");
       res = (*f_perform)(curl);

       (*f_cleanup)(curl);
    }

    //dlclose(handle);

    return 0;
}
