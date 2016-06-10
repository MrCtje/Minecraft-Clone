#include "objmodelloader.h"

OBJModelLoader::OBJModelLoader():vertexCount(0), indexCount(0), texturePresent(false)
{

}
OBJModelLoader::~OBJModelLoader()
{

}

Model* OBJModelLoader::loadOBJModel(const char* filePath){
   std::ifstream file(filePath);
   std::string buffer;

   if(file.is_open()){
       std::cout << "Loaded OBJ: " << filePath << std::endl;
        while(std::getline(file, buffer)){
            std::string temp(buffer.substr(0,2));
            if(temp == "v "){   //Reads vertices from file
                vertexCount++;
                util::split(buffer.substr(2), ' ', vertexVector);
            }
            else if(temp == "vt"){   //Reads vertices from file
                texturePresent = true;
                util::split(buffer.substr(3), ' ', texturesVector);
            }
            else if(temp == "vn"){   //Reads vertices from file
                util::split(buffer.substr(3), ' ', normalVector);
            }
            else if(temp == "f "){ //Reads indices from file
                indexCount++;
                util::split(buffer.substr(2), ' ', indexVector);
            }
        }
        //Allocates space for vertices and indices
        Model *model = new Model;
        model->vertices = new GLfloat[vertexVector.size()];
        model->indices = new GLuint[indexVector.size()];
        if(texturePresent)
            model->textures = new GLfloat[texturesVector.size()];
            //model->textures = new GLfloat[indexVector.size()];
        model->normals = new GLfloat[normalVector.size()];

        std::cout<< "IndexVectorSize: " << indexVector.size() << std::endl;
        std::cout<< "VertexVectorSize: " << vertexVector.size() << std::endl;
        std::cout<< "NormalVectorSize: " << normalVector.size() << std::endl;
        if(texturePresent)
            std::cout<< "TextureVectorSize: " << texturesVector.size() << std::endl;

        //Fill Vertices in allocated array
        for (uint c = 0; c < vertexVector.size(); c++) {
            model->vertices[c] = std::stof(vertexVector[c]);
        }
        //Fill Indices, textures and normals in allocated arrays
        for (uint i = 0; i < indexVector.size(); ++i) {
            model->indices[i] = std::stoi(indexVector[i].substr(0,indexVector[i].find_first_of('/'))) - 1;
            if(texturePresent)
                model->textures[model->indices[i] * 2]  = std::stof(texturesVector[std::stoi(indexVector[i].substr(indexVector[i].find_first_of('/')+1, indexVector[i].find_last_of('/'))) - 1]);
                model->textures[model->indices[i] * 2 + 1] =1 - std::stof(texturesVector[std::stoi(indexVector[i].substr(indexVector[i].find_first_of('/')+1, indexVector[i].find_last_of('/')))]);
//                model->textures[model->indices[i] * 2 + 1] = 1 - std::stof(texturesVector[std::stoi(indexVector[i].substr(indexVector[i].find_first_of('/')+1, indexVector[i].find_last_of('/')))]);
            model->normals[1] = std::stof(normalVector[std::stoi(indexVector[i].substr(indexVector[i].find_last_of('/') + 1)) - 1]);
        }

        model->vertexCount = getVertexCount();
        model->indexCount = getIndexCount();
        if(texturePresent)
            model->texturesCount = texturesVector.size()/2;
        model->normalsCount = normalVector.size()/3;
        std::vector<std::string>().swap(vertexVector);
        std::vector<std::string>().swap(indexVector);
        if(texturePresent)
            std::vector<std::string>().swap(texturesVector);
        std::vector<std::string>().swap(normalVector);
        return model;
   }else{
        throw "File couldn't open";
   }
}

GLuint OBJModelLoader::getVertexCount(){

    return vertexVector.size()/3; // Size / 3 because xyz represents 1 vertex
}

GLuint OBJModelLoader::getIndexCount()
{
    return indexVector.size();
}
