#include <iostream>
#include<vector>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

class Vendedor
{
    private:
        int codigo;
        string nombre;
        string apellido;
        string sexo;
        int dni;

    public:
        Vendedor()
        {
        }
        ~Vendedor()
        {
        }

    void setCodigo(int code)
    {
        codigo = code;
    }
    void setNombre(string name)
    {
        nombre = name;
    }
    void setApellido(string lname)
    {
        apellido = lname;
    }
    void setSexo(string gen)
    {
        sexo = gen;
    }
    void setDni(int id)
    {
        dni = id;
    }

    int getCodigo()
    {
        return this->codigo;
    }
    string getNombre()
    {
        return this->nombre;
    }
    string getApellido()
    {
        return this->apellido;
    }
    string getSexo()
    {
        return this->sexo;
    }
    int getDni()
    {
        return this->dni;
    }
};

class VendedorVector
{
    private:
        vector<Vendedor> vectorVendedor;
    public:
        VendedorVector()
        {
            vector<Vendedor> vectorVendedor;
        }

        void add(Vendedor obj)
        {
            vectorVendedor.push_back(obj);
        }

        Vendedor get(int pos)
        {
            return vectorVendedor[pos];
        }

        int rows()
        {
            return vectorVendedor.size();
        }

    Vendedor buscarPorCodigo(int codigo)
		{
			for(int i=0;i<rows();i++)			
			{
				if(codigo == get(i).getCodigo())
				{
					return get(i);
				}
			}
		}
    int getPostArray(Vendedor obj)
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getCodigo() == get(i).getCodigo())
				{
					return i;
				}
			}
			return -1;
		}

    void remove(Vendedor obj)
    {
        vectorVendedor.erase(vectorVendedor.begin()+getPostArray(obj));
    }
    void grabarEnArchivo(Vendedor seller)
    {
        try
        {
           fstream archivoVendedor;
           archivoVendedor.open("vendedores.csv",ios::app);
           if(archivoVendedor.is_open())
           {
               archivoVendedor<<seller.getCodigo()<<";"<<seller.getNombre()<<";"<<seller.getApellido()<<";"<<seller.getSexo()<<";"<<
               seller.getDni()<<endl;
               archivoVendedor.close();
           }
        }
        catch(exception e)
        {
            cout << "--Hubo un erro al grabar el registro--" << '\n';
        }
        
    }

    void cargarDatosDelArchivo()
    {
        try
        {
            int i;
            size_t posi;
            string linea;
            string temporal[5];
            fstream archivoVendedor;
            archivoVendedor.open("vendedores.csv",ios::in);

            if( archivoVendedor.is_open())
            {
                while(!archivoVendedor.eof())
                {
                    while(getline(archivoVendedor, linea))
                    {
                        i=0;
                        while((posi = linea.find(";")) != string::npos )
                        {
                            temporal[i] = linea.substr(0,posi);
                            linea.erase(0,posi + 1);
                            i++;
                        }
               

    Vendedor seller;
    seller.setCodigo(std::stoi(temporal[0]));
    seller.setNombre(temporal[1]);
    seller.setApellido(temporal[2]);
    seller.setSexo(temporal[3]);
    seller.setDni(std::stoi(temporal[4]));
    add(seller);
                    }
                }
            }
archivoVendedor.close();
        }
        catch(exception e)
        {
            cout<<"Ocurrio un error al leer el archivo";
        }
    }
};

VendedorVector vendedorVec;

void menuDeOpciones();
void adicionarVendedores();
void eliminarVendedores();
void modificarVendedores();
void buscarVendedor();
void listarVendedores();

int main()
{
    menuDeOpciones();
}

void menuDeOpciones()
{
    int opcion;
    do{
        cout<<"MENU DE OPCIONES\n";
		cout<<"Ingresar Nuevos Alumnos" <<	" [1]\n";
		cout<<"Eliminar Nuevos Alumnos"<<" [2]\n";
		cout<<"Modificar Nuevos Alumnos"<<" [3]\n";
		cout<<"Buscar Nuevos Alumnos"<<" [4]\n";
		cout<<"Listar Alumnos"<<" [5]\n";
		cout<<"Salir"<<" [6]\n";
		cout<<"Ingrese una opcion[1-6]:";
		cin>>opcion;

        switch(opcion)
        {
            case 1 : system("cls");
                     adicionarVendedores();
                        break;
            case 2 : eliminarVendedores();
                        break;
            case 3 : modificarVendedores();
                        break;
            case 4 : buscarVendedor();
                        break;
            case 5 : system("cls");
                    listarVendedores();
                    break;
            case 6 : cout<<"***PROGRAMA CERRADO CORRECTAMENTE***";
                    exit(0);
                    break;
            default:cout<<"Ingrese una opcion correcta[1-6]"<<endl;
            cout<<endl;
        }    

    }
    while(opcion!=6);
}

void adicionarVendedores()
{
    int code;
    string name;
    string lname;
    string gen;
    int id;
    string respuesta;

    do
    {
    cout<<"Ingresar Codigo del Vendedor: ";
    cin>>code;
    cin.ignore();

    cout<<"Ingresar Nombre del Vendedor: ";
    getline(cin,name);

    cout<<"Ingresar Apellido del Vendedor: ";
    getline(cin, lname);

    cout<<"Ingresar Genero del Vendedor: ";
    getline(cin, gen);

    cout<<"Ingresar DNI del Vendedor: ";
    cin>>id;
    cin.ignore();

    Vendedor seller;
    seller.setCodigo(code);
    seller.setNombre(name);
    seller.setApellido(lname);
    seller.setSexo(gen);
    seller.setDni(id);

    vendedorVec.add(seller);

    vendedorVec.grabarEnArchivo(seller);
    cout<<"Si desea continuar escriba(SI o si)";
    cin>>respuesta;
    system("cls");
    }
while(respuesta == "SI" || respuesta == "si");
}

void listarVendedores()
{
    for(int i=0;i<vendedorVec.rows();i++)
	{
		cout<<"Codigo: "<<vendedorVec.get(i).getCodigo()<<"\n";	
		cout<<"Nombre: "<<vendedorVec.get(i).getNombre()<<"\n";	
        cout<<"Apellido: "<<vendedorVec.get(i).getApellido()<<"\n";
        cout<<"Genero: "<<vendedorVec.get(i).getSexo()<<"\n";
        cout<<"DNI: "<<vendedorVec.get(i).getDni()<<"\n";
	}	
	system("pause");
	system("cls");
}


void eliminarVendedores()
{
	
}
void modificarVendedores()
{
}
void buscarVendedor()
{
	
}