#include <stdio.h>
#include <string.h>
#include <math.h>
// 定义备注长度在十字以内
#define NOTE 41
// 结构体设置
typedef struct
{
    char name[10];
    int month;
    int day;
    char note[NOTE];
} Term;
// 指针设置
void p_term(Term *t)
{
    printf("%s %d月%d日 ", t->name, t->month, t->day);
    if (t->note[0] != '\0')
    {
        printf("(%s)", t->note);
    }
}
// 转化日期
int Yearday(int month, int day)
{
    int monthday[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};
    int yearday = 0;
    for (int i = 0; i < month - 1; i++)
    {
        yearday += monthday[i];
    }
    yearday += day;
    return yearday;
}
// 主菜单
int main()
{
    // 结构体设置
    Term term_a[] = {
        {"立春", 2, 3, ""},
        {"雨水", 2, 18, ""},
        {"惊蛰", 3, 5, ""},
        {"春分", 3, 20, ""},
        {"清明", 4, 4, ""},
        {"谷雨", 4, 20, ""},
        {"立夏", 5, 5, ""},
        {"小满", 5, 21, ""},
        {"芒种", 6, 6, ""},
        {"夏至", 6, 21, ""},
        {"小暑", 7, 7, ""},
        {"大暑", 7, 23, ""},
        {"立秋", 8, 7, ""},
        {"处暑", 8, 23, ""},
        {"白露", 9, 7, ""},
        {"秋分", 9, 23, ""},
        {"寒露", 10, 8, ""},
        {"霜降", 10, 23, ""},
        {"立冬", 11, 7, ""},
        {"小雪", 11, 22, ""},
        {"大雪", 12, 7, ""},
        {"冬至", 12, 22, ""},
        {"小寒", 1, 5, ""},
        {"大寒", 1, 20, ""}};
    int re_a = 1; // 主菜单
    int re_b = 0; // 查询子菜单
    int re_c = 0; // 备注子菜单
    int rem;
    // 主菜单
    while (re_a)
    {

        printf("——————————————————————\n");
        printf("| 二十四节气查询系统 |\n");
        printf("|1.查询              |\n");
        printf("|2.备注              |\n");
        printf("|3.初始化            |\n");
        printf("|4.退出              |\n");
        printf("——————————————————————\n");
        printf("请输入你所需的选项数字:");
        int begin;
        if (scanf("%d", &begin) != 1)
        {

            while (getchar() != '\n')
                ;
            printf("输入无效,请输入正确的选项数字\n");
            printf("\n");
            continue;
        }
        while (getchar() != '\n')
            ;
        switch (begin)
        {
            // 查询
        case 1:
            re_b = 1;
            while (re_b)
            {

                printf("————————————————————————\n");
                printf("|1.查询所有节气及其备注|\n");
                printf("|2.查询某节气的日期    |\n");
                printf("|3.查询某月节气        |\n");
                printf("|4.查询距某日最近的节气|\n");
                printf("|5.返回主菜单          |\n");
                printf("————————————————————————\n");

                printf("请输入你所需的选项数字:");
                int find;
                if (scanf("%d", &find) != 1)
                {

                    while (getchar() != '\n')
                        ;
                    printf("输入无效,请输入正确的选项数字\n");
                    printf("\n");
                    continue;
                }
                while (getchar() != '\n')
                    ;
                switch (find)
                {
                    // 查询所有节气及其备注
                case 1:
                {
                    Term *a = term_a;
                    for (int i = 0; i < 24; i++)
                    {
                        p_term(a);
                        a++;
                        printf("\n");
                    }

                    break;
                }

                // 查询某节气的日期
                case 2:
                {
                    while (1)
                    {
                        printf("请输入想要查询的节气名称:");
                        char find_name[10];
                        scanf("%s", find_name);
                        while (getchar() != '\n')
                            ;
                        Term *b = term_a;
                        int found_b = 0;
                        for (int i = 0; i < 24; i++)
                        {
                            if (strcmp(find_name, b->name) == 0)
                            {
                                printf("%d月%d日\n", b->month, b->day);
                                printf("\n");
                                found_b = 1;
                                break;
                            }
                            b++;
                        }
                        if (!found_b)
                        {
                            printf("未找到该节气,请检查后重新输入\n");
                            printf("\n");
                            continue;
                        }
                        break;
                    }
                    break;
                }
                    // 查询某月节气
                case 3:
                {
                    while (1)
                    {
                        printf("请输入目标月份:");
                        int find_month;
                        scanf("%d", &find_month);
                        while (getchar() != '\n')
                            ;
                        Term *c = term_a;
                        int found_c = 0;
                        for (int i = 0; i < 24; i++)
                        {
                            if (find_month == c->month)
                            {
                                printf("%s\n", c->name);
                                printf("\n");
                                found_c = 1;
                                break;
                            }
                            c++;
                        }
                        if (!found_c)
                        {
                            printf("输入错误，请检查后重新输入\n");
                            printf("\n");
                            continue;
                        }
                        break;
                    }
                    break;
                }
                // 查询距某日最近的节气
                case 4:
                {
                    while (1)
                    {
                        printf("请输入目标日期,如1月1日:");
                        int find_month_a, find_day;
                        scanf("%d月%d日", &find_month_a, &find_day);
                        while (getchar() != '\n')
                            ;
                        int yearday = Yearday(find_month_a, find_day);
                        Term *d = term_a;
                        int min_diff = 611;
                        Term near;
                        strcpy(near.name, "");
                        for (int i = 0; i < 24; i++)
                        {
                            int term_month = d->month;
                            int term_day = d->day;
                            int term_yearday = Yearday(term_month, term_day);
                            int diff = abs(term_yearday - yearday);
                            if (diff < min_diff)
                            {
                                min_diff = diff;
                                near = *d;
                            }
                            d++;
                        }
                        if (strlen(near.name) > 0)
                        {
                            printf("最近的节气是:%s %d月%d日,相差%d天\n", near.name, near.month, near.day, min_diff);
                            printf("\n");
                        }
                        else
                        {
                            printf("输入错误，请检查后重新输入\n");
                            printf("\n");
                            continue;
                        }
                        break;
                    }
                    break;
                }
                // 返回主菜单
                case 5:
                    re_b = 0;
                    break;
                default:
                {
                    printf("输入无效，请输入正确的选项数字\n");
                    printf("\n");
                    break;
                }
                }
            }
            break;
            // 备注
        case 2:
        {
            re_b = 1;
            while (re_b)
            {
                printf("————————————————————————\n");
                printf("|1.增加备注            |\n");
                printf("|2.删除备注            |\n");
                printf("|3.返回主菜单          |\n");
                printf("————————————————————————\n");
                printf("请输入你所需的选项数字:");
                int rem;
                if (scanf("%d", &rem) != 1)
                {

                    while (getchar() != '\n')
                        ;
                    printf("输入无效,请输入正确的选项数字\n");
                    printf("\n");
                    continue;
                }
                while (getchar() != '\n')
                    ;
                switch (rem)
                {
                    // 增加备注
                case 1:
                {
                    while (1)
                    {
                        printf("请输入想要增加备注的节气名称:");
                        char rem_name_a[10];
                        scanf("%s", rem_name_a);
                        while (getchar() != '\n')
                            ;
                        Term *e = term_a;
                        int rem_a = 0;
                        for (int i = 0; i < 24; i++)
                        {
                            if (strcmp(rem_name_a, e->name) == 0)
                            {
                                rem_a = 1;
                                printf("请输入备注(十字以内):");
                                char add_note[NOTE];
                                scanf("%10s", add_note);
                                while (getchar() != '\n')
                                    ;
                                strcpy(e->note, add_note);
                                printf("添加备注成功，可在'查询'中查询修改后的节气表\n");
                                break;
                            }
                            e++;
                        }
                        if (!rem_a)
                        {
                            printf("未找到该节气,请检查后重新输入\n");
                            printf("\n");
                            continue;
                        }
                        break;
                    }
                    break;
                }
                // 删除备注
                case 2:
                {
                    while (1)
                    {
                        printf("请输入想要删除备注的节气名称:");
                        char rem_name_b[10];
                        scanf("%s", rem_name_b);
                        while (getchar() != '\n')
                            ;
                        Term *f = term_a;
                        int rem_b = 0;
                        for (int i = 0; i < 24; i++)
                        {
                            if (strcmp(rem_name_b, f->name) == 0)
                            {
                                rem_b = 1;

                                strcpy(f->note, "");
                                printf("删除备注成功，可在'查询'中查询修改后的节气表\n");
                                break;
                            }
                            f++;
                        }
                        if (!rem_b)
                        {
                            printf("未找到该节气,请检查后重新输入\n");
                            printf("\n");
                            continue;
                        }
                        break;
                    }
                    break;
                }
                // 返回主菜单
                case 3:
                    re_b = 0;
                    break;
                default:
                {
                    printf("输入无效，请输入正确的选项数字\n");
                    printf("\n");
                    break;
                }
                }
            }
            break;
        }
            // 初始化
        case 3:
        {
            re_c = 1;
            while (re_c)
            {
                printf("一旦初始化所有备注都将消失，请确认是否要初始化\n");
                printf("请输入1'确认'或2'再想想':");
                int init;
                if (scanf("%d", &init) != 1)
                {

                    while (getchar() != '\n')
                        ;
                    printf("输入无效,请输入正确的选项数字\n");
                    printf("\n");
                    continue;
                }
                while (getchar() != '\n')
                    ;
                switch (init)
                {
                // 确认
                case 1:
                {
                    Term *g = term_a;
                    for (int i = 0; i < 24; i++)
                    {
                        strcpy(g->note, "");
                        g++;
                    }
                    printf("初始化成功\n");
                    re_c = 0;
                    break;
                }
                // 返回主菜单
                case 2:
                {
                    re_c = 0;
                    break;
                }
                default:
                {
                    printf("输入无效，请输入正确的选项数字\n");
                    printf("\n");
                    break;
                }
                }
            }
            break;
        }
        // 退出
        case 4:
        {
            re_a = 0;
            break;
        }

        default:
        {

            printf("输入无效，请输入正确的选项数字");
            printf("\n");
        }
        }
    }

    return 0;
}