/*程序填空，不要改变与输入输出有关的语句。
输入一个正整数 looptimes (0<looptimes<10)，做 looptimes 次下列运算：
某城市普通出租车收费标准如下："起步里程3公里，起步费10元；超起步里程但总里程在10公里内，每公里租费2元；
总里程超过10公里以上的部分加收50%的回空补贴费，即每公里租费3元。营运过程中，因路阻及乘客要求临时停车的，
每5分钟按1公里租费计收。运价计费尾数四舍五入，保留到元。"
编写程序，输入行驶里程(公里)与等待时间(分钟)，计算并输出乘客应支付的车费(元)。
3  	    (looptimes=3) 
1.6 2 52    (行驶1.6公里,等待2分52秒)
3.1 6 15    (行驶3.1公里,等待6分15秒)
11.8 2 30   (行驶11.8公里,等待2分30秒)
输出
cost = 10
cost = 13
cost = 31
*/
#include <stdio.h>
int main(void)
{
    int looptimes, ri;
    int minutes, seconds;
    double cost, mile;
	int a;
    scanf("%d", &looptimes);
    for(ri = 1; ri <= looptimes; ri++){
        scanf("%lf%d%d", &mile, &minutes, &seconds);
         seconds=seconds+minutes*60;
         mile=mile+seconds/300.0;
         if(mile<=3){
         	cost=10;
         }
         else if(mile<=10){
         	cost=10+(mile-3)*2;
         }
         else{
         	cost=24+(mile-10)*3;
         }
	printf("cost = %.0f\n", cost);
    }
}
