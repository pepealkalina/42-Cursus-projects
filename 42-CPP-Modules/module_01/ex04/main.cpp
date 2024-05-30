/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:35:31 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/12/05 12:46:17 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> //libreria para operar con archivos

int replaceFile(std::string fileContent, char **argv)
{
    std::ofstream   fileReplaced;
    int             filePosition;

    fileReplaced.open(std::string(argv[1]) + ".replace"); //crea un archivo con el nombre del arg y añade .replace
    int i = 0;
    while (i < fileContent.size())
    {
        filePosition = fileContent.find(argv[2], i); //mira si el string a buscar esta a partir de esa posicion, exactamente la primera aparaicion, y si es asi filePosition es la posicion de este
        if (filePosition != -1 && filePosition == i)
        {
            fileReplaced << argv[3];    //escribe dentro del archivo el string que reemplaza en vez del string a buscar
            i += std::string(argv[2]).size() - 1; //salta la longitud del string para seguir buscando
        }
        else
            fileReplaced << fileContent[i]; //si lo anterior no sucede entonces escribe el contenido original
        i++;
    }
    fileReplaced.close(); //cierra el archivo
    return (0);
}

int main(int argc, char **argv)
{
    std::ifstream   fileToRead;
    std::string     fileContent;
    char            c;
    
    if (argc != 4)
    {
        std::cout << "Wrong arguments. Usage: ./replace <file to replace> word1 word2" << std::endl;
        return (1);
    }
    fileToRead.open(argv[1]);
    if (fileToRead.fail()) //abre el archivo y con fileToRead.fail() verifica que no hay fallo al abrir este
    {
        std::cout << "Error opening the file" << std::endl;
        return (1);
    }
    while (!fileToRead.eof() && fileToRead >> std::noskipws >> c) //lee el archivo si saltarse los espacios en blanco y los guarda en fileContent
        fileContent += c;
    fileToRead.close(); //cierra el archivo
    replaceFile(fileContent, argv); //hace la funcion de reemplazar los dos string
    return 0;
}
