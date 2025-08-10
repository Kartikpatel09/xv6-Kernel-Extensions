#include "types.h"
#include "user.h"
int main(){
while(1){
printf(1,">>>>");
char buff[1024];
int byteRead;
while((byteRead=read(0,buff,1024))>0){
write(1,buff,byteRead);
}

}
exit();

}
