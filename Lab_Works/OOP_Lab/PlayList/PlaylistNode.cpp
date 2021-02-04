#include <iostream>
#include "PlaylistNode.h"

PlaylistNode::PlaylistNode()
{
	this->uniqueID="none";
	this->songName="none";
	this->artistName="none";
	this->songLength=0;
	this->nextNodePtr=0;

}
PlaylistNode::PlaylistNode(string id,string name,string artist,int length)
{
	this->uniqueID=id;
        this->songName=name;
        this->artistName=artist;
        this->songLength=length;
}
void PlaylistNode::InsertAfter(PlaylistNode *current)
{
	PlaylistNode *temp = nullptr;

	temp = this->nextNodePtr;
	this->nextNodePtr = current;
	current->nextNodePtr = temp;

}
void PlaylistNode::SetNext(PlaylistNode *current)
{
	this->nextNodePtr = current;
}

string PlaylistNode::GetID()
{
	return this->uniqueID;
}

string PlaylistNode::GetSongName()
{
	return this->songName;
}

string PlaylistNode::GetArtistName()
{
	return this->artistName;
}

int PlaylistNode::GetSongLength()
{
	return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext()
{
	return this->nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode()
{
	cout<<"Unique ID: "<<this->uniqueID<<endl;
	cout<<"Song Name: "<<this->songName<<endl;
	cout<<"Artist Name: "<<this->artistName<<endl;
	cout<<"Song Length (in seconds): "<<this->songLength<<endl<<endl;
}

