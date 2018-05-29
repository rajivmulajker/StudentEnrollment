#include "fdset.h"

FieldDesSet::FieldDesSet(file_name aFilename)
 {
  FldPtr fptr;
  string fname2;
  ifstream inFile;

  strcpy(fname,aFilename);
  //size = 0;
  current = -1;
  error = false;
  inFile.open(fname, ios::in);
  if(inFile.good())
     {
      //inFile >> size;
      //inFile.get();
      for(int i = 0; i < size; i++)
       {
	 fptr = new Field_descriptor;

	 //inFile.getline(fptr -> get_tname(), MAXSTR);
	 //strip(fptr -> get_tname());
	 //inFile.getline("Field Name",MAXSTR);
	 //strip("Field Name");

	 inFile.getline(fptr ->  get_fldname(), MAXSTR);
	 strip(fptr ->  get_fldname());

	 //inFile.getline("Field Type",MAXSTR);
	 //strip("Field Type");
	 inFile >> fptr -> get_fldtype();

	 //inFile >> fptr -> get_offset();
	 //inFile.getline("Field Size",MAXSTR);
	 //strip("Field Size");
	 inFile >> fptr -> get_fldsize();

	 s[i] = fptr;
      }
      inFile.close();
    }
   else
   {
      ;
   }
}


FieldDesSet::FieldDesSet()
 {
   ;
 }

FieldDesSet::~FieldDesSet()
 {
  for(int i = 0; i<size; i++)
  {
   delete s[i];
  }
 }

void FieldDesSet::add(FldPtr fptr)
 {
    s[size++] = fptr;
 }

void FieldDesSet::get_set()
 {
  fstream file1;
  fstream file;
  string strarr[MAXSTR];
  string strarr1[MAXSTR];
  //string dump[8];
  FldPtr fptr=NULL;
  int i=0,num=0,length=0,state=0,k=0;
  int count;
  int array[10];
  string dump[100];
  string str1,str2,str3,str4,str5,flag,entry;
  char choice;
  char ch;

  for(int j=0; j<=10; j++)
    array[j] = 10;

  enum Position{in,out};
  Position s = in;
  std::cout << "\n> ";
  getstring(entry,MAXSTR);
  strcpy(str5,entry);
  check(str5,entry,str5);

  strcpy(str4,"XXXX");
  strcpy(flag,"ok");

  while((!strcmp(entry,"create") || !strcmp(entry,"c")) ||
	 (!strcmp(entry,"use") || !strcmp(entry,"u")) ||
	 (!strcmp(entry,"add") || !strcmp(entry,"a")) ||
	 (!strcmp(entry,"structure") || !strcmp(entry,"s")) ||
	 (!strcmp(entry,"list") || !strcmp(entry,"l")) ||
	 (!strcmp(entry,"release") || !strcmp(entry,"r")) ||
	 (!strcmp(entry,"dump") || !strcmp(entry,"d")) ||
	 (!strcmp(entry,"q") || !strcmp(entry,"quit")) ||
	 (!strcmp(entry,"undelete") || !strcmp(entry,"un")) ||
	 (!strcmp(entry,"delete") || !strcmp(entry,"del")) ||
	 (!strcmp(entry,"help") || !strcmp(entry,"?"))  ||
	 (!strcmp(entry,"dir")) || (!strcmp(entry,"cls")))
   {
  while(!strcmp(str5,"create") || !strcmp(str5,"c") || !strcmp(str5,"use") || !strcmp(str5,"u"))
	  {
	   if(strcmp(str4,"XXXX") || !strcmp(flag,"error"))
	    {
	     std::cout << "\n************Error table in use\n";
	     std::cout << str4 << "> ";
	     getstring(entry,MAXSTR);
	     strcpy(str5,entry);
	     check(str5,entry,str5);
	     strcpy(flag,"error");
	     }
	   else
	    {
	    std::cout << "\n*****Error no file specified\n";
	    std::cout << "> ";
	    getstring(entry,MAXSTR);
	    strcpy(str5,entry);
	    check(str5,entry,str5);
	   }
	  }

    if(!strcmp(entry,"create") || !strcmp(entry,"c"))
    {
     if(strcmp(str4,"XXXX") || !strcmp(flag,"error"))
      {
       std::cout << "\n************Error table in use\n";
       std::cout << str4 << "> ";
       getstring(entry,MAXSTR);
       strcpy(str5,entry);
       check(str5,entry,str5);
       strcpy(flag,"error");
       }
     else if(strcmp(flag,"error"))
       {
       Table_descriptor tdes;
       state=tdes.read_in(str5);
       if(state==1)
	{
	 strcpy(str1,tdes.get_tablename());
	 strcpy(str2,str1);
	 strcpy(str3,str2);
	 strcpy(str4,str3);
	 strcat(str1,".txt");
	 strcat(str2,".dic");
	 strcpy(flag,"ok");
	 num = tdes.get_numfields();
	 std::cin.get();
//	 tdes.file_in1(str1);
	 if(num == 0)
	 {
	  std::cout << "Wrong Entry!!" << std::endl;
	  std::cout << std::endl << "> ";
	  getstring(entry,MAXSTR);
	  strcpy(str5,entry);
	  check(str5,entry,str5);
	  strcpy(str4,"XXXX");
	  }
	 }
       else
	 {
	   std::cout << "\n**************Error table already exists\n";
	   std::cout << std::endl << "> ";
	   getstring(entry,MAXSTR);
	   strcpy(str5,entry);
	   check(str5,entry,str5);
	 }
     }
   }

    if((!strcmp(entry,"create") || !strcmp(entry,"c")) && strcmp(str4,"XXXX") && strcmp(flag,"error"))
	{
	string temp;
	FieldDesSet fldset(str1);
	file1.open("FILE.DIC",ios::app | ios::out | ios::in);
	file.open(str4,ios::app | ios::out | ios::in);
	count=0;
	int temporary=0;
//	std::cin.get();
	for(int i=0; i<num; i++)
	 {
	  std::cout << "\nField #" << i+1 << std::endl;
	  fptr = new Field_descriptor;

	  fldset.add(fptr);
	  std::cin.get();
	  for(int i=0; i<=count; i++)
	  {
	   if(!strcmp(strarr[i],fptr->get_fldname()))
	    {
	     string str;
	     std::cout << "\nDuplicate field name. Enter next one. ";
	     getstring(str,MAXSTR);
	     strcpy(fptr->get_fldname(),str);
	     i=0;
	    }
	   }
	  strcpy(strarr[i],fptr->get_fldname());
	  strcpy(strarr1[i],str3);
	  length = strlen(strarr[i]);
	  file.write(strarr[i],length);
	  file.write("\n",1);
	  count=i++;
//	  file1
	  temporary += fptr->get_fldsize();
	}
     cout << "\n*********New table " << str4 << " created" << endl;

     itoa(temporary,temp,10);
     file1.write("\n",1);
     file1.write("TableName ",strlen("TableName "));
     file1.write(str4,strlen(str4));
     file1.write("\n",1);
     file1.write("FieldSize ",strlen("FieldSize "));
     file1.write(temp,strlen(temp));
     temporary=0;
     itoa(temporary,temp,10);
     file1.write("\n",1);
     file1.write("Records ",strlen("Records "));
     file1.write(temp,strlen(temp));
    file1.seekg(0);
    file1.read(str4,strlen(str4));
    file1.close();

     strcpy(str4,"XXXX");
     cout << endl << "> ";
     getstring(entry,MAXSTR);
     strcpy(str5,entry);
     check(str5,entry,str5);
     strcpy(flag,"ok");
     s=out;
     file.seekg(0);
     file.read(strarr[i],length);
     file.close();
     fldset.file_out();
   }


    while(!strcmp(entry,"use") || !strcmp(entry,"u"))
     {
    while(!strcmp(str5,"create") || !strcmp(str5,"c") || !strcmp(str5,"use") || !strcmp(str5,"u"))
	  {
	    std::cout << "\n*****Error no file specified\n";
	    std::cout << "> ";
	    getstring(entry,MAXSTR);
	    strcpy(str5,entry);
	    check(str5,entry,str5);
	  }

	 Table_descriptor tdes;
	 state = tdes.read_in1(str5);
	 if(state == 1)
	  {
	   if(strcmp(str4,"XXXX") && strcmp(str4,tdes.get_tablename()))
	     cout << "\n************" << str4 << " released" << endl;
	   strcpy(str1,tdes.get_tablename());
	   strcpy(str2,str1);
	   strcpy(str3,str2);
	   strcpy(str4,str3);
	   strcat(str1,".txt");
	   strcat(str2,".dic");
	   cout << endl << str4 << "> ";
	   getstring(entry,MAXSTR);
	   strcpy(str5,entry);
	   check(str5,entry,str5);
	   s=out;
	  }
	 else
	  {
	   if(strcmp(str4,"XXXX"))
	   {
	    std::cout << std::endl << str4 << "> ";
	    getstring(entry,MAXSTR);
	    strcpy(str5,entry);
	    check(str5,entry,str5);
	    s=out;
	   }
	   else
	    {
	     cout << endl << "> ";
	     getstring(entry,MAXSTR);
	     strcpy(str5,entry);
	     check(str5,entry,str5);
	     strcpy(flag,"ok");
	     s=out;
	     }
	  }
     }

     while(!strcmp(entry,"cls"))
      {
       clrscr();
       if(strcmp(str4,"XXXX"))
	{
	  std::cout << std::endl << str4 << "> ";
	  getstring(entry,MAXSTR);
	  strcpy(str5,entry);
	  check(str5,entry,str5);
	}
       else
	 {
	  std::cout << std::endl << "> ";
	  getstring(entry,MAXSTR);
	  strcpy(str5,entry);
	  check(str5,entry,str5);
	 }
       }

     while(!strcmp(entry,"release") || !strcmp(entry,"r"))
     {
       if(!strcmp(str4,"XXXX"))
	 {
	 std::cout << "********Error no table in use" << std::endl;
	 std::cout << std::endl << "> ";
	 getstring(entry,MAXSTR);
	 strcpy(str5,entry);
	 check(str5,entry,str5);
	}
       else
       {
       strcpy(str4,"XXXX");
       std::cout << std::endl << "> ";
       getstring(entry,MAXSTR);
       strcpy(str5,entry);
       check(str5,entry,str5);
       strcpy(flag,"ok");
       }
     }

     while(!strcmp(entry,"structure") || !strcmp(entry,"s"))
      {
       if(!strcmp(str4,"XXXX"))
	 {
	 std::cout << "********Error no table in use" << endl;
	 std::cout << endl << "> ";
	 getstring(entry,MAXSTR);
	 strcpy(str5,entry);
	 check(str5,entry,str5);
	 }
       else
	{
       structure(str1);
       std::cout << endl << str4 << "> ";
       getstring(entry,MAXSTR);
       strcpy(str5,entry);
       check(str5,entry,str5);
	}
      }

  while(!strcmp(entry,"delete") || !strcmp(entry,"del") || !strcmp(entry,"undelete") || !strcmp(entry,"un"))
  {
   string str6,str7,str8;
   int sum=0,num=0,index=0,temp1=0,rec_size=0;
   k=get_offset(array,str1);    //str1=*.txt
   temp1=dump_data(array,k,dump,str2);       //str2=*.dic
//   temp=temp1;
   for(int i=0; i<= k; i++)
     sum += array[i];

//   sum = sum + 10;
   temp1 = (temp1+1) * 10;
   rec_size = temp1 / sum;
   sum = sum/10;
   if(!strcmp(str4,"XXXX"))
    {
     std::cout << "********Error no table in use" << endl;
     std::cout << endl << "> ";
     getstring(entry,MAXSTR);
     strcpy(str5,entry);
     check(str5,entry,str5);
    }
   else
    {
     num = atoi(str5);

     if(num > rec_size+1 || num == 0)
      {
       std::cout << "Error!!Incompatable number." << endl;
       std::cout << endl << str4 << "> ";
       getstring(entry,MAXSTR);
       strcpy(str5,entry);
       check(str5,entry,str5);
       continue;
      }

     index = (num-1)*sum;
     strcpy(str6,dump[index]);
     for(i=0; i<10; i++)
      {
	if(i==0)
	 {
	  str7[0] = '*';
	  continue;
	 }
	str7[i] = str6[i];
      }
      str7[i] = '\0';
      strcpy(dump[index],str7);
      strcpy(str8,dump[index+1]);

      if(!strcmp(entry,"delete") || !strcmp(entry,"del"))
	del(str2,str8,num);
      else
	undel(str2,str8,num);
/*
      for(k=0; k<=temp; k++)
       std::cout << dump[k] << endl;
*/
     s = in;

     std::cout << endl << str4 << "> ";
     getstring(entry,MAXSTR);
     strcpy(str5,entry);
     check(str5,entry,str5);
    }
  }

    while(!strcmp(entry,"list") || !strcmp(entry,"l"))
     {
      if(!strcmp(str4,"XXXX"))
	 {
	 std::cout << "********Error no table in use" << endl;
	 std::cout << endl << "> ";
	 getstring(entry,MAXSTR);
	 strcpy(str5,entry);
	 check(str5,entry,str5);
	 }
      else
       {
       int count=-1;
       count=list(str3,count);
       std::cout << "\n_________________________________________________\n" << endl;

       count=list(str2,count+1);

       std::cout << endl << str4 << "> ";
       getstring(entry,MAXSTR);
       strcpy(str5,entry);
       check(str5,entry,str5);
       }
     }

    while((!strcmp(entry,"add") || !strcmp(entry,"a")) && strcmp(str5,"-r"))
     {
      if(!strcmp(str4,"XXXX"))
	 {
	 std::cout << "********Error no table in use" << endl;
	 std::cout << endl << "> ";
	 getstring(entry,MAXSTR);
	 strcpy(str5,entry);
	 check(str5,entry,str5);
	 }
      else
      {
//       string str6,str7,str8;
//       int sum=0,rec_size=0,temp1=0;
//       k=get_offset(array,str1);    //str1=*.txt
//       temp1=dump_data(array,k,dump,str2);       //str2=*.dic
       //temp=temp1;
//       if(temp1 != 0)
//       {
//       for(int i=0; i<= k; i++)
//	 sum += array[i];

//   sum = sum + 10;
//       temp1 = (temp1+1) * 10;
//       rec_size = temp1 / sum;
//      sum = sum/10;
       get_data(str3,strarr,strarr1);
//       add_size("FILE.DIC",rec_size+2,str4);
//       }
/*       else
	{
	 get_data(str3,strarr,strarr1);
	 add_size("FILE.DIC",rec_size+1,str4);
	}
*/       std::cout << endl << str4 << "> ";
       getstring(entry,MAXSTR);
       strcpy(str5,entry);
       check(str5,entry,str5);
      }
    }

    while((!strcmp(entry,"add") || !strcmp(entry,"a")) && !strcmp(str5,"-r"))
      {
      if(!strcmp(str4,"XXXX"))
	 {
	 std::cout << "********Error no table in use" << endl;
	 std::cout << endl << "> ";
	 getstring(entry,MAXSTR);
	 strcpy(str5,entry);
	 check(str5,entry,str5);
	 }
      else
      {
       char ch = 'y';
//       string str6,str7,str8;
//       int sum=0,rec_size=0,temp1=0;

//       k=get_offset(array,str1);    //str1=*.txt
//       temp1=dump_data(array,k,dump,str2);       //str2=*.dic

       while(ch == 'y' || ch == 'Y')
	{
	 get_data(str3,strarr,strarr1);
	 std::cout << endl << "Do you want to add(y/n): ";
	 std::cin >> ch;
	 std::cin.get();
	}

//       k=get_offset(array,str1);    //str1=*.txt
//       temp1=dump_data(array,k,dump,str2);       //str2=*.dic
       //temp=temp1;
/*       if(temp1 != 0)
       {
       k=get_offset(array,str1);    //str1=*.txt
       temp1=dump_data(array,k,dump,str2);       //str2=*.dic

       for(int i=0; i<= k; i++)
	 sum += array[i];

//     sum = sum + 10;
       temp1 = (temp1+1) * 10;
       rec_size = temp1 / sum;
//     sum = sum/10;
       add_size("FILE.DIC",rec_size+1,str4);
       }
       else
	{
	 k=get_offset(array,str1);    //str1=*.txt
	 temp1=dump_data(array,k,dump,str2);       //str2=*.dic

	 for(int i=0; i<= k; i++)
	   sum += array[i];

	 temp1 = (temp1+1) * 10;
	 rec_size = temp1 / sum;
	 add_size("FILE.DIC",rec_size,str4);
	}                                   */

       std::cout << std::endl << str4 << "> ";
       getstring(entry,MAXSTR);
       strcpy(str5,entry);
       check(str5,entry,str5);
     }
   }
  while(!strcmp(entry,"dump") || !strcmp(entry,"d"))
  {
   if(!strcmp(str4,"XXXX"))
    {
     std::cout << "********Error no table in use" << std::endl;
     std::cout << std::endl << "> ";
     getstring(entry,MAXSTR);
     strcpy(str5,entry);
     check(str5,entry,str5);
    }
   else
    {
      string temparr[100];
      string str6,str7;
//     if(s == out)
//     {
     int temp=0;
     k=get_offset(array,str1);    //str1=*.txt
     temp=dump_data(array,k,dump,str2);       //str2=*.dic
//   }

/*     if(s==out)
      {
	for(k=0; k<=temp; k++)
	   strcpy(temparr[k],dump[k]);
	std::cout << temparr[k];
      }
     else
     { */
     for(k=0; k<=temp; k++)
      {
//       std::cout << dump[k] << std::endl;
	 strcpy(str6,dump[k]);
	 if(str6[0] == '*')
	  {
 //	   int temp1=0;
	   strcpy(str7,dump[k-1]);
	   str7[0] = '*';
	   strcpy(dump[k-1],str7);
	   str6[0] = ' ';
	   strcpy(dump[k],str6);
	  }
      }

     for(k=0; k<=temp; k++)
       std::cout << dump[k] << std::endl;

     std::cout << std::endl << str4 << "> ";
     getstring(entry,MAXSTR);
     strcpy(str5,entry);
     check(str5,entry,str5);
    }//else
  }//while dump

  while(!strcmp(entry,"dir"))
   {
     dir_list("FILE.DIC");
     if(!strcmp(str4,"XXXX"))
      {
       std::cout << std::endl << "> ";
       getstring(entry,MAXSTR);
       strcpy(str5,entry);
       check(str5,entry,str5);
     }
    else
     {
       std::cout << std::endl << str4 << "> ";
       getstring(entry,MAXSTR);
       strcpy(str5,entry);
       check(str5,entry,str5);
     }
  }

 while(!strcmp(entry,"help") || !strcmp(entry,"?"))
   {
    help_note();
    if(!strcmp(str4,"XXXX"))
      {
       std::cout << std::endl << "> ";
       getstring(entry,MAXSTR);
       strcpy(str5,entry);
       check(str5,entry,str5);
     }
    else
     {
       std::cout << std::endl << str4 << "> ";
       getstring(entry,MAXSTR);
       strcpy(str5,entry);
       check(str5,entry,str5);
     }
  }

 while((strcmp(entry,"create") && strcmp(entry,"c")) &&
	 (strcmp(entry,"use") && strcmp(entry,"u"))  &&
	 (strcmp(entry,"add") && strcmp(entry,"a"))  &&
	 (strcmp(entry,"structure") && strcmp(entry,"s")) &&
	 (strcmp(entry,"list") && strcmp(entry,"l")) &&
	 (strcmp(entry,"release") && strcmp(entry,"r")) &&
	 (strcmp(entry,"dump") && strcmp(entry,"d")) &&
	 (strcmp(entry,"quit") && strcmp(entry,"q")) &&
	 (strcmp(entry,"delete") && strcmp(entry,"del")) &&
	 (strcmp(entry,"undelete") && strcmp(entry,"un")) &&
	 (strcmp(entry,"help") && strcmp(entry,"?")) &&
	 (strcmp(entry,"dir")) && (strcmp(entry,"cls")))
       {
       if(!strcmp(str4,"XXXX"))
       {
	std::cout << "\n****** Invalid command!! Type 'help' or '?' for help!!!";
	std::cout << std::endl << "> ";
	getstring(entry,MAXSTR);
	strcpy(str5,entry);
	check(str5,entry,str5);
       }
       else
       {
	std::cout << "\n****** Invalid command!! Type 'help' or '?' for help!!!";
	std::cout << std::endl << str4 << "> ";
	getstring(entry,MAXSTR);
	strcpy(str5,entry);
	check(str5,entry,str5);
       }
    }
   if(!strcmp(entry,"quit") || !strcmp(entry,"q"))
       exit(0);
 }
}

void FieldDesSet::dir_list(file_name aFilename)
 {
   FILE* stream;
   fstream file;
   char choice;
   string str;
   int i=0, j=0;
   string* string1;

   stream = fopen(aFilename, "r+");
   fseek(stream, 0, SEEK_SET);

     while(choice != EOF)
      {
      choice = fgetc(stream);
      if(choice == ' ' || choice == '\n')
       {
	 str[i] = '\0';
	 strcpy(string1[j],str);
	 i=0;
	 j++;
       }
     else
       {
	str[i] = choice;
	i++;
       }
     }
     str[i] = '\0';

//    file.open(aFilename,ios::in, ios::out);

    for(i=0; i<j; i++)
     {
       if(i== 7 || i%7 == 1)
	 std::cout << std::endl;
      if(strcmp(string1[i],"TableName") && strcmp(string1[i],"FieldSize") && strcmp(string1[i],"Records"))
	 std::cout << string1[i] << "        ";
     }

    file.seekg(0);
    file.read(string1[i],strlen(string1[i]));
    fclose(stream);
   }


void FieldDesSet::add_size(file_name aFilename,int rec_size,file_name aFile2)
 {
   FILE* stream;
   fstream file;
   char choice;
   string* string1;
   string str,str1,str2;
   int count=0,i=0,j=0,k=0;

   itoa(rec_size,str1,10);

   stream = fopen(aFilename, "r+");
   fseek(stream, 0, SEEK_SET);


     while(choice != EOF)
      {
      choice = fgetc(stream);
      if(choice == ' ' || choice == '\n')
       {
	 str[i] = '\0';
	 strcpy(string1[j],str);
	 i=0;
	 j++;
       }
     else
       {
	str[i] = choice;
	i++;
       }
     }
     str[i] = '\0';

     for(i=0; i<j; i++)
      {
       if(!strcmp(string1[i],aFile2))
	  {
	    while(strcmp(string1[i],"Records"))
		i++;
	    strcpy(string1[i+1],str1);
	    break;
	  }
       }

    file.open(aFilename,ios::in | ios::out);

    for(i=0; i<=j; i++)
     {
       file.write(string1[i],strlen(string1[i]));
       file.write("\n",1);
       strip(string1[i]);
    }

    file.seekg(0);
    file.read(string1[i],strlen(string1[i]));
    fclose(stream);
   }

void FieldDesSet::undel(file_name aFilename,string aString,int index)
 {
  string str,str2,str3;
  string str1[100];
  int i=0, j=0,k=0,length=0;
  FILE* stream;
  char choice;
  fstream file;

//  strcpy(str4,aFilename);
//  strcat(aFilename,".dic");

  stream = fopen(aFilename, "r+");
  fseek(stream, 0, SEEK_SET);

  while(choice != EOF)
      {
      choice = fgetc(stream);

      if(choice =='\n' && i == 0)
	 continue;

      if(choice == '\n')
       {
	 str[i] = '\0';
	 strcpy(str1[j],str);
	 i=0;
	 j++;
	}
      else
       {
	str[i] = choice;
	i++;
       }
     }
//    std::cout << std::endl;
    str[i] ='\0';
    strcpy(str1[j],str);
    fclose(stream);

    file.open(aFilename,ios::in | ios::out);

    for(i=0; i<=j; i++)
     {
      strcpy(str,str1[i]);
//      length=strlen(str);
      while(str[k] != '\0')
       {
	 if(str[k] == '*')
	   str3[k] = '*';
	 else
	   str3[k] = str[k];
	 k++;
	}

      while(k%10 != 0)
       {
	str3[k] = '+';
	k++;
       }
      str3[k]='\0';

      if(!strcmp(str3,aString))
       {
	 strcpy(str2,str1[i]);
	 str2[0] = ' ';
	 strcpy(str1[i],str2);
       }
      //std::cout << str1[i] << std::endl;
      length=strlen(str1[i]);
      file.write("\n",1);
      file.write(str1[i],length);
      strip(str1[i]);
      k=0;
    }
   //file.write("\n",1);
  file.seekg(0);
  file.read(str1[i],length);
}


void FieldDesSet::del(file_name aFilename,string aString,int index)
 {
  string str,str2,str3;
  string str1[100];
  int i=0, j=0,k=0,length=0;
  FILE* stream;
  char choice;
  fstream file;

//  strcpy(str4,aFilename);
//  strcat(aFilename,".dic");

  stream = fopen(aFilename, "r+");
  fseek(stream, 0, SEEK_SET);

  while(choice != EOF)
      {
      choice = fgetc(stream);

      if(choice =='\n' && i == 0)
	 continue;

      if(choice == '\n')
       {
	 str[i] = '\0';
	 strcpy(str1[j],str);
	 i=0;
	 j++;
	}
      else
       {
	str[i] = choice;
	i++;
       }
     }
//    std::cout << std::endl;
    str[i] ='\0';
    strcpy(str1[j],str);
    fclose(stream);

    file.open(aFilename,ios::in | ios::out);

    for(i=0; i<=j; i++)
     {
      strcpy(str,str1[i]);
//      length=strlen(str);
      while(str[k] != '\0')
       {
	 if(str[k] == ' ')
	   str3[k] = '+';
	 else
	   str3[k] = str[k];
	 k++;
	}

      while(k%10 != 0)
       {
	str3[k] = '+';
	k++;
       }
      str3[k]='\0';

      if(!strcmp(str3,aString))
       {
	 strcpy(str2,str1[i]);
	 str2[0] = '*';
	 strcpy(str1[i],str2);
       }
      //std::cout << str1[i] << std::endl;
      length=strlen(str1[i]);
      file.write("\n",1);
      file.write(str1[i],length);
      strip(str1[i]);
      k=0;
    }
   //file.write("\n",1);
  file.seekg(0);
  file.read(str1[i],length);
}

int FieldDesSet::dump_data(int array[],int size1,string dump[], file_name aFilename)
 {
   string str,str1,str2;
   static char* number;
   int i=0,j=0,k=0,count=0,size=0,counter=0,temp;
   enum Bool{false,true};
   Bool bool = false;
   FILE* stream;
   char choice;

    strcpy(str2,"000");
    strcpy(number,"1");
    strcpy(str1,"+0001+++++");
    //strcat(str2,str1);
    stream = fopen(aFilename, "r+");
    fseek(stream, 0, SEEK_SET);

     while(choice != EOF)
      {
      choice = fgetc(stream);
      if(choice == ' ')
	choice = '+';
      size=array[k];
      if(choice == '\n'|| i%10 == 9)
       {
	 if(j==0 && i == 0)
	   {
//	    continue;
	    strcpy(dump[j],str1);
	    temp=atoi(number);
	    temp++;
	    itoa(temp, number, 10);
	    strcpy(str1,number);
	    strcat(str2,str1);
	    //strcpy(str1,str2);
	    i=0;
	    while(i < strlen(str2))
	     {
	       str1[0] = '+';
	       str1[i+1] = str2[i];
	       i++;
	     }
	     while(i%10 != 0)
	      {
	       str1[i+1] = '+';
	       i++;
	      }
	    str1[i] = '\0';
	    strcpy(str2,"000");
	    j++;
	    i=0;
	    continue;
	   }

	 if(choice == '\n')
	   bool = true;

	 while(i%10 != 0)
	  {
	   str[i] = '+';
	   i++;
	  }

	 if(i%10 == 0 && i !=0)
	    {
	     str[i] = '\0';
	     strcpy(dump[j],str);
	     j++;
	     counter++;
	     i=0;
	    }

	 while(bool == true && (counter*10) != size)
	   {
	    if(i == 0)
	     {
	     while(i < 10)
	      {
	      str[i] = '+';
	      i++;
	      }
	     strcpy(dump[j],str);
	     j++;
	     i=0;
	    }
	    else
	     {
	      while(i%10 != 0)
	       {
		str[i] = '+';
		i++;
	       }
	       strcpy(dump[j],str);
	       j++;
	       i=0;
	       }
	      counter++;
	      if(counter*10 == size)
		 bool = false;
	    }

	 i=0;
	 counter=0;
	 k++;
	 count++;
	 if(count == size1)
	  {
	   k=0;
	   count=0;
	   strcpy(dump[j],str1);
	   temp=atoi(number);
	   temp++;
	   itoa(temp, number, 10);
	   strcpy(str1,number);
	   strcat(str2,str1);
	   //strcpy(str1,str2);
	   i=0;
	   while(i < strlen(str2))
	     {
	       str1[0] = '+';
	       str1[i+1] = str2[i];
	       i++;
	      }
	    while((i%10) != 0)
	     {
	      str1[i+1] = '+';
	      i++;
	     }
	   str1[i] = '\0';
	   strcpy(str2,"000");
	   j++;
	   i=0;
	  }
       }
      else
       {
	 str[i] = choice;
	 i++;
       }
     }

   str[i] = '\0';
   while(i%10 != 0)
     {
       str[i] = '+';
       i++;
     }
   strcpy(dump[j],str);
   i=0;
  fclose(stream);
  return j;
 }

void FieldDesSet::check(string aString,string aString1, string aString2)
 {
  int count =0;
  for(int i=0; i<strlen(aString+1); i++)
   {
    aString1[i] = aString[i];
    if(aString[i]==' ')
     {
      aString1[i] = '\0';
      count = i+1;
      break;
     }
    }
   for(i=0; i<strlen(aString+1); i++)
    {
     aString2[i] = aString[i+count];
     if(aString[i] == '\n')
      {
      aString2[i] = '\n';
      break;
      }
    }
   }


int FieldDesSet::list(file_name aFile1,int count)
 {
  FILE* stream;
  char choice;
  int tcount=0;

    stream = fopen(aFile1, "r+");
    fseek(stream, 0, SEEK_SET);

     while(choice != EOF)
      {
      choice = fgetc(stream);

      if(choice == '\n')
       {
	tcount++;
	if(tcount == count)
	  {
	  std::cout << std::endl;
	  tcount=0;
	  }
	else
	  std::cout << "   ";
       }
      else
	std::cout << choice;

     }
//    std::cout << std::endl;
    fclose(stream);
    std::cout << std::endl;
    count = tcount;
    return count;
   }

void FieldDesSet::structure(file_name aFilename)
 {
   FILE* stream;
   char choice;
   string* string1;
//   int* array[k];
   string str;
   int count=0,i=0,j=0,k=0;

//   std::cout << "\n**************************************************\n";
   std::cout << "  Field name          Field Type        Field Size\n";
//   std::cout << "\n**************************************************\n";

    stream = fopen(aFilename, "r+");
    fseek(stream, 0, SEEK_SET);

     while(choice != EOF)
      {
      choice = fgetc(stream);
      if(choice == ' ' || choice == '\n')
       {
	 str[i] = '\0';
	 strcpy(string1[j],str);
	 i=0;
	 j++;
       }
     else
       {
	str[i] = choice;
	i++;
       }

      /*if(choice == '\n')
       {
	count++;
	if(count%3 == 0)
	  std::cout << std::endl;
	else
	  std::cout << setw(10);
       }
      else
	std::cout << choice;*/
     }

//     fclose(stream);
     for(i=0; i<j; i++)
      {
      if(!strcmp(string1[i],"FieldSize"))
	  {
	   i=i+1;
	   std::cout << atoi(string1[i]);
	   std::cout << std::endl;
	  }
       else if(strcmp(string1[i],"FieldName") && strcmp(string1[i],"FieldType"))
	   std::cout << string1[i] << setw(10);
      }
     fclose(stream);
 }

void FieldDesSet::display(char** array,int k)
 {
 for(int j=0; j<=k; j++)
 {
  for (int i=0; i<10; i++)
      std::cout << array[j][i];
  std::cout << std::endl;
 }
 }

void FieldDesSet::help_note()
 {
  std::cout << std::endl;
  std::cout << "c    or create <file name>     ------  To create a table" << std::endl;
  std::cout << "u    or use    <file name>     ------  To use a table" << std::endl;
  std::cout << "s    or structure              ------  Structure of table" << std::endl;
  std::cout << "l    or list                   ------  List the table contents" << std::endl;
  std::cout << "a    or  add                   ------  add records to table"  << std::endl;
  std::cout << "a -r or  add -r                ------  add recursively" << std::endl;
  std::cout << "del  or delete <rec num>       ------  to delete the record" << std::endl;
  std::cout << "un   or undelete < rec num>    ------  to undelete the record" << std::endl;
  std::cout << "dump or d                      ------  dump the records" << std::endl;
  std::cout << "dir                            ------  list the tables present" << std::endl;
  std::cout << "cls                            ------  clears the screen" << std::endl;
  std::cout << "q    or quit                   ------  quits the system" << std::endl;
 }

int FieldDesSet::get_offset(int array[],file_name aFilename)
 {
   FILE* stream;
   char choice;
   string* string1;
   //int array[k];
   string str;
   int count=0,i=0,j=0,k=0;

    stream = fopen(aFilename, "r+");
    fseek(stream, 0, SEEK_SET);

     while(choice != EOF)
      {
      choice = fgetc(stream);
      if(choice == ' ' || choice == '\n')
       {
	 str[i] = '\0';
	 strcpy(string1[j],str);
	 i=0;
	 j++;
       }
     else
       {
	str[i] = choice;
	i++;
       }
     }

     for(i=0; i<j; i++)
      {
      if(!strcmp(string1[i],"FieldSize"))
	  {
	   i=i+1;
	   array[k]=atoi(string1[i]);
	   if(array[k] < 10)
	     array[k] = 10;
	   else if(array[k] < 20 && array[k] > 10)
	     array[k] = 20;
	   k++;
	  }
       }
     fclose(stream);
     //for(i=0; i<k; i++)
     //  std::cout << array[i] << " ";
    return k;
 }

int FieldDesSet::check_fldsize(file_name aFilename,int array[])
 {
   FILE* stream;
   char choice;
   string* string1;
   string str;
   int count=0,i=0,j=0,k=0,m=0;

    stream = fopen(aFilename, "r+");
    fseek(stream, 0, SEEK_SET);

     while(choice != EOF)
      {
      choice = fgetc(stream);
      if(choice == ' ' || choice == '\n')
       {
	 str[i] = '\0';
	 strcpy(string1[j],str);
	 i=0;
	 j++;
       }
     else
       {
	str[i] = choice;
	i++;
       }
     }

     for(i=0; i<j; i++)
      {
      if(!strcmp(string1[i],"FieldSize"))
	  {
	   i=i+1;
	   array[m]= atoi(string1[i]);
	   m++;
	  }
      }
     fclose(stream);
     return m;
 }

void FieldDesSet::get_data(file_name aFilename,string* string1, string* string2)
 {
  int count=0;
  fstream file;
  FILE *stream;

  string str1,str2,str3,str4,str5;
  FldPtr fptr=NULL;
  int length=0,i=0,j=0,temp=0;
  char ch,choice;

  strcpy(str2,aFilename);
  strcpy(str4,aFilename);
  strcat(str4,".dic");

  file.open(str4,ios::app | ios::out | ios::in);

    stream = fopen(str2, "r+");
    fseek(stream, 0, SEEK_SET);


     while(choice != EOF)
      {
      choice = fgetc(stream);
      if(choice != '\n')
	str3[i]=choice;
      else
	str3[i]='\0';

      i++;

      if(choice == '\n')
	{
	  strcpy(string1[j],str3);
	  j++;
	  i=0;
	  count++;
	  continue;
	}
     }

     fclose(stream);
    for(i=0; i<count;i++)
     {
       std::cout << string1[i] << " ";
       getstring(str1,MAXSTR);

       strcpy(str5," ");
       str5[0] = ' ';
       if(temp == 0)
	{
	 strcat(str5,str1);
	 strcpy(str1,str5);
	 temp++;
	}
       std::cout << std::endl;
       file.write("\n",1);
//       file.write("",1);
       length=strlen(str1);
       file.write(str1,length);
       strip(str1);
     }
  //file.write("\n",1);
  file.seekg(0);
  file.read(str1,length);
 }

void FieldDesSet::read_in()
  {
   FldPtr fptr=NULL;
    for(int i=0; i<2; i++)
     {
      fptr = FldPtr(s[i]);
      std::cout << fptr->get_fldname();
      getstring(str1,MAXSTR);
     }
   }

/*int FieldDesSet::dump(int j,string str1,char** array)
 {
  int length = strlen(str1);

  if(length < 10)
   {
   for(int i=0; i<10; i++)
    {
     array[j][i+1] = str1[i];
     if(str1[i] == '\0')
	break;
    }
   }
 else
  {
   for(int i=0; i<10; i++)
    {
     array[j][i] = str1[i];
     if(i==9)
      {
       j++;
       for(i=9; i<16; i++)
	{
	 array[j][i-9] = str1[i];
	 if(str1[i] == '\0')
	   break;
	}
      }
    }
    return j;
  }
}
  */

void FieldDesSet::file_in1(ifstream& inFile)
 {
  inFile >> str1;
 }

void FieldDesSet::file_out1(ofstream& outFile)
 {
  outFile << str1;
 }

 void main()
  {
   FieldDesSet fset;
   fset.get_set();
  }
