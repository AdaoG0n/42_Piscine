#include <unistd.h>

void print_hex(int num)
{
    char hex_digits[] = "0123456789abcdef";
    
    if (num == 0)
    {
        write(1, "0", 1);
        return;
    }
    
    int temp = num;
    int digits = 0;
    while (temp > 0)
    {
        temp /= 16;
        digits++;
    }
    
    char hex[digits];
    for (int i = digits - 1; i >= 0; i--)
    {
        hex[i] = hex_digits[num % 16];
        num /= 16;
    }
    
    write(1, hex, digits);
}

int ft_atoi(char *str)
{
    int result = 0;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int num = ft_atoi(argv[1]);
        print_hex(num);
    }
    write(1, "\n", 1);
    return 0;
}
