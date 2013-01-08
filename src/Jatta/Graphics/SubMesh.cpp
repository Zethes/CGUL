/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "SubMesh.h"
#include <cstring>

_JATTA_EXPORT Jatta::SubMesh::SubMesh()
{
}

void Jatta::SubMesh::Setup(Type type, UInt32 vertexCount)
{
	this->type = type;

	glGenVertexArrays(1, &this->vertexArray);
	this->vertexCount = vertexCount;

	indices = nullptr;
}

_JATTA_EXPORT void Jatta::SubMesh::AddBuffer(float* buffer, Byte count, UInt32 index)
{
	if (count < 2 || count > 4)
	{
		throw std::runtime_error("AddBuffer count invalid (must be 2-4).");
	}

	// bind the mesh so that we can modify it
	glBindVertexArray(this->vertexArray);

	// generate a new vertex buffer
	unsigned int object;
	glGenBuffers(1, &object);

	// bind the vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, object);

	// set the data of this buffer
	glBufferData(GL_ARRAY_BUFFER, (this->vertexCount * count) * sizeof(GLfloat), (float*)buffer, GL_STATIC_DRAW);

	// setup the attribute pointer to whatever was passed in
	glVertexAttribPointer(index, count, GL_FLOAT, GL_FALSE, 0, 0);

	// set the attribute index
	glEnableVertexAttribArray(index);

	// we done here, unbind the mesh
	glBindVertexArray(0);
}

_JATTA_EXPORT void Jatta::SubMesh::AddBuffer(Jatta::Float2* buffer, unsigned int index)
{
    // bind the mesh so that we can modify it
    glBindVertexArray(this->vertexArray);

    // generate a new vertex buffer
    unsigned int object;
    glGenBuffers(1, &object);

    // bind the vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, object);

    // set the data of this buffer
    glBufferData(GL_ARRAY_BUFFER, (this->vertexCount * 2) * sizeof(GLfloat), (float*)buffer, GL_STATIC_DRAW);

    // setup the attribute pointer to whatever was passed in
    glVertexAttribPointer(index, 2, GL_FLOAT, GL_FALSE, 0, 0);

    // set the attribute index
    glEnableVertexAttribArray(index);

    // we done here, unbind the mesh
    glBindVertexArray(0);
}

_JATTA_EXPORT void Jatta::SubMesh::AddBuffer(Jatta::Float3* buffer, unsigned int index)
{
    // bind the mesh so that we can modify it
    glBindVertexArray(this->vertexArray);

    // generate a new vertex buffer
    unsigned int object;
    glGenBuffers(1, &object);

    // bind the vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, object);

    // set the data of this buffer
    glBufferData(GL_ARRAY_BUFFER, (this->vertexCount * 3) * sizeof(GLfloat), (float*)buffer, GL_STATIC_DRAW);

    // setup the attribute pointer to whatever was passed in
    glVertexAttribPointer(index, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // set the attribute index
    glEnableVertexAttribArray(index);

    // we done here, unbind the mesh
    glBindVertexArray(0);
}

_JATTA_EXPORT void Jatta::SubMesh::AddBuffer(Jatta::Float4* buffer, unsigned int index)
{
    // bind the mesh so that we can modify it
    glBindVertexArray(this->vertexArray);

    // generate a new vertex buffer
    unsigned int object;
    glGenBuffers(1, &object);

    // bind the vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, object);

    // set the data of this buffer
    glBufferData(GL_ARRAY_BUFFER, (this->vertexCount * 4) * sizeof(GLfloat), (float*)buffer, GL_STATIC_DRAW);

    // setup the attribute pointer to whatever was passed in
    glVertexAttribPointer(index, 4, GL_FLOAT, GL_FALSE, 0, 0);

    // set the attribute index
    glEnableVertexAttribArray(index);

    // we done here, unbind the mesh
    glBindVertexArray(0);
}

_JATTA_EXPORT void Jatta::SubMesh::AddBuffer(Jatta::Color* buffer, UInt32 index)
{
	// bind the mesh so that we can modify it
	    glBindVertexArray(this->vertexArray);

	    // generate a new vertex buffer
	    unsigned int object;
	    glGenBuffers(1, &object);

	    // bind the vertex buffer
	    glBindBuffer(GL_ARRAY_BUFFER, object);

	    // set the data of this buffer
	    //float colors[this->vertexCount * 4];
	    //for ()
	    glBufferData(GL_ARRAY_BUFFER, (this->vertexCount * 4) * sizeof(GLubyte), (GLubyte*)buffer, GL_STATIC_DRAW);

	    // setup the attribute pointer to whatever was passed in
	    glVertexAttribPointer(index, 4, GL_FLOAT, GL_FALSE, 0, 0);

	    // set the attribute index
	    glEnableVertexAttribArray(index);

	    // we done here, unbind the mesh
	    glBindVertexArray(0);
}

_JATTA_EXPORT void Jatta::SubMesh::SetIndexBuffer(unsigned int* buffer, unsigned int size)
{
    if (buffer == nullptr)
    {
        delete[] indices;
        indices = nullptr;
    }
    else
    {
        this->indices = new unsigned int[size];
        memcpy(this->indices, buffer, size * sizeof(unsigned int));
    }
    this->indexCount = size;
}

_JATTA_EXPORT void Jatta::SubMesh::Draw()
{
    // draw this sh!te
    glBindVertexArray(this->vertexArray);
    if (this->indices == nullptr)
    {
        glDrawArrays((GLenum)this->type, 0, vertexCount);
    }
    else
    {
        glDrawElements((GLenum)this->type, this->indexCount, GL_UNSIGNED_INT, this->indices);
    }
    glBindVertexArray(0);
}
