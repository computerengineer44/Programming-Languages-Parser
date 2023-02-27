
#include <stdio.h>
#include <locale.h> 

int main() {
	setlocale(LC_ALL, "Turkish"); //T�RK�E KARAKTERLER�N TANINMASI.
	int i=0, d=0, len;
	char ilkHarf, c[1000], dosyaAdi[10];
	printf("t\t\t\t A�mak �stedi�iniz Kaynak Kodu Dosyan�z�n �smini Giriniz: ");
	scanf("%s", &dosyaAdi);
	FILE *dosya;
	
	if ((dosya = fopen(dosyaAdi,"r"))==NULL){ //KULLANICI TARAFINDAN ALINAN DOSYANIN A�ILMASI
		printf("Hata! Dosya A��lam�yor.");
		exit(1);
		}
	
	fscanf(dosya,"%[^\?]",c);
	
	printf("\n\n\n\n\n\t\t\t\t\t\tKODUNUZUN INDENTATION KURALLARINA G�RE YAZDIRILMASI\n\n\n\n");//KODUN INDENTAT�ON KURALLARINA G�RE YAZDIRILMASI
	len = strlen(c);
	
	while(len>0){
		printf("%c",c[i]);
		i++;
		len--;
	}
	
	char token[500];
	i=0;
	
	len = strlen(c);
	
	while(len>0){
		char z=c[i];
		if(isspace(z) == 0){
			token[d]=c[i];
			d++;
		}
	i++;
	len--;
	}
	
	printf("t\t\t\t\t\tG�RD���N�Z KOD DOSYANIZIN KEL�MELE�T�R�LM�� HAL�\n\n\n\n");//KEL�MELE�M�� HAL�
	i=0;
	len = strlen(token);
	
	while(len>0){
		ilkHarf=token[i];
		int ikinciHarf = token[i-1];
		if(ispunct(ilkHarf) != 0){
			if(ispunct(ikinciHarf) != 0){
				printf("%c,",token[i]); }
			else{
				printf(",%c,",token[i]); } }
		else{
				printf("%c",token[i]);}
		
		i++;
		len--;
	}
	
	printf("\n\n");
	
	len = strlen(token);
	
	for(i = 0; i <= len; i++){
		
		if(token[i]<32)
			break;
		
		char ilkHarf = token[i], ikinciHarf = token[i+1];
		i = i+2;
		
		if(ilkHarf == 'i' && ikinciHarf == 'f'){
			ilkHarf = token[i];
			ikinciHarf = token[i+1];
			i = i+2;
			
			if(ilkHarf == '(' && ((ikinciHarf>=65 && ikinciHarf<=70) 
			|| (ikinciHarf>=97 && ikinciHarf<=102)) ){
				ilkHarf = token[i];
				ikinciHarf = token[i+1];
				i = i+2;
				
				if( (ilkHarf == '=' || ilkHarf == '<' || ilkHarf == '>' ) && 
				(ikinciHarf == '=') ){
					ilkHarf = token[i];
					ikinciHarf = token[i+1];
					i = i+2;
					
					if(((ilkHarf>=65 && ilkHarf<=70) 
					|| (ilkHarf>=97 && ilkHarf<=102)) && ikinciHarf == ')'){
						ilkHarf = token[i];
						ikinciHarf = token[i+1];
						i = i+2;
						
						
						int parantezKontrol = 0;
						while(token[i] != '}' && parantezKontrol < 6){
							i++;
							++parantezKontrol;
						}
						
						if(parantezKontrol == 6){
							printf("Dosya yanlis");//dosya hatas�
							return 0;
						}
						
					}else{
						printf("Dosya yanlis");//dosya hatas�
						return 0;
					}
					
				}else if( (ilkHarf == '<' || ilkHarf == '>') &&
				 ((ikinciHarf>=65 && ikinciHarf<=70) || (ikinciHarf>=97 && ikinciHarf<=102)) ){
					ilkHarf = token[i];
					ikinciHarf = token[i+1];
					i = i+2;
					
					if( ilkHarf ==')'){
						int parantezKontrol = 0;
						while(token[i] != '}' && parantezKontrol < 6){
							i++;
							++parantezKontrol;
						}
						if(parantezKontrol == 6){
							printf("Dosya yanlis");//dosya hatas�
							return 0;
						}
					}else{
						printf("Dosya yanlis");//dosya hatas�
						return 0;
					}
					
				}else{
					printf("Dosya yanlis");//dosya hatas�
					return 0;
				}
				
			}else{
				printf("Dosya yanlis");//dosya hatas�
				return 0;
			}
			
		}else if(ilkHarf=='e' && ikinciHarf == 'l'){//el k�sm�n�n kontrol�
			ilkHarf = token[i];
			ikinciHarf = token[i+1];
			i = i+2;
			
			if(ilkHarf == 's' && ikinciHarf == 'e'){//-el -se	k�sm�n�n kontrol�
				ilkHarf = token[i];
				ikinciHarf = token[i+1];
				i = i+2;
				
				if(ilkHarf == 'i' && ikinciHarf == 'f'){//if k�sm�n�n kontrol�
					ilkHarf = token[i];
					ikinciHarf = token[i+1];
					i = i+2;
			
					if(ilkHarf == '(' && ((ikinciHarf>=65 && ikinciHarf<=70) || 
					(ikinciHarf>=97 && ikinciHarf<=102)) ){ //harf aral��� 
						ilkHarf = token[i];
						ikinciHarf = token[i+1];
						i = i+2;
				
						if( (ilkHarf == '=' || ilkHarf == '<' || ilkHarf == '>' ) && 
						(ikinciHarf == '=') ){
							ilkHarf = token[i];
							ikinciHarf = token[i+1];
							i = i+2;
					
							if(((ilkHarf>=65 && ilkHarf<=70) || (ilkHarf>=97 && ilkHarf<=102)) && 
							ikinciHarf == ')'){
								ilkHarf = token[i];
								ikinciHarf = token[i+1];
								i = i+2;
						
						
								int parantezKontrol = 0;
								while(token[i] != '}' && parantezKontrol < 6){
									i++;
									++parantezKontrol;
								}
						
								if(parantezKontrol == 6){
									printf("Dosya yanlis"); //dosya hatas�
									return 0;
								}
						
							}else{
								printf("Dosya yanlis"); //dosya hatas�
								return 0;
							}
					
						}else if( (ilkHarf == '<' || ilkHarf == '>') && ((ikinciHarf>=65 && ikinciHarf<=70) || 
						(ikinciHarf>=97 && ikinciHarf<=102)) ){
							ilkHarf = token[i];
							ikinciHarf = token[i+1];
							i = i+2;
					
							if( ilkHarf ==')'){
								int parantezKontrol = 0;
								while(token[i] != '}' && parantezKontrol < 6){
									i++;
									++parantezKontrol;
								}
								if(parantezKontrol == 6){
									printf("Dosya yanlis"); //dosya hatas�
									return 0;
								}
							}else{
								printf("Dosya yanlis"); //dosya hatas�
								return 0;
							}
					
				}else{
					printf("Dosya yanlis");// dosya hatas�
					return 0;
				}
				
			}else{
				printf("Dosya yanlis"); // dosya hatas�
				return 0;
			}
			
		}else if(ilkHarf == '{' && ((ikinciHarf>=65 && ikinciHarf<=70) 
		|| (ikinciHarf>=97 && ikinciHarf<=102))){
					ilkHarf = token[i];
					ikinciHarf = token[i+1];
					i = i+2;
					
					int parantezKontrol = 0;
					while(token[i] != '}' && parantezKontrol < 6){
						i++;
						++parantezKontrol;
					}
					if(parantezKontrol == 6){
						printf("Dosya yanlis"); //dosya hatas�
						return 0;
					}
				}else{
					printf("Dosya yanlis"); //dosya hatas�
					return 0;
				}
				
			}else{
			printf("Dosya yanlis"); //dosya hatas�
			return 0;
		}
			
		}else{
			printf("Dosya yanlis"); //dosya hatas�
			return 0;
		}
		
	}
	
	printf("Dosya dogru"); //dosya do�ruland�
	
	fclose(dosya);
	return 0;
}	
