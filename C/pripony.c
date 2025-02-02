char get_filename(char castle[],char filename[],char preset[])
{
    int presetlen = strlen(preset);
    int len = (strlen(castle)) + presetlen;
    filename[len];
    for (int i = 0; i < len; i++)
    {
        filename[i]=castle[i];
       
        if(i == (int) strlen(castle))
        {
             for (int a = 0; a < presetlen+1; a++)
             {
                filename[i++] = preset[a];  
             }
        }
    }
    return filename;
}
// funckia spravi priponu