#include <iostream>
#include <stdio.h>
#include <Windows.h>

int main()
{
	HWND ventana = FindWindowA(NULL, "Zuma Deluxe 1.0");

	if (ventana != 0)
	{
		void *p = 0;
		
		printf("ingrese direccion: ");
		
		fflush(stdin);

		scanf_s("%p", &p);
	

		DWORD pid;
		int nuevavida = 3;
		char c = 'c';
		
		while (c != 'x') 
		{
			
			GetWindowThreadProcessId(ventana, &pid);
			HANDLE openproceso = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

			WriteProcessMemory(openproceso, (LPVOID)p, &nuevavida, sizeof(nuevavida), 0);

			
			printf("'\n presione cualquier tecla (x = salir): ");
			while ((getchar()) != '\n');
			c = getchar();
		}

		// printf("\nCAMBIO\n");
		
	}

	return 0;
}
