#ifndef CUSHOME_H
#define CUSHOME_H

/*
 CustomHOME�̊J��Ԃ��擾
 
 @return :
			0 : Close
			1 : Open
*/
int cusHomeGetStatus();

/*
 CustomHOME�̃��j���[����܂�

 @return :
			0 : success
			-1 :Not open
*/
int cusHomeClose();


#endif