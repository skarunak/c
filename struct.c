#pragma pack(1)
typedef struct {
int i:4;
int j:4;
int z:6;
int x:4;
} a;

main ()
{
printf ("\n %d ", sizeof(a));
}
