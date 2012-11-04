#include "gtest/gtest.h"
#include "../include/TwoDArray.h"
//#include "../src/Sparse2D/TwoDArray.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

TEST(TwoDArrayTest, ConstructDestruct) {

  TwoDArray<int> iArray[3]={TwoDArray<int>(3,3,3),TwoDArray<int>(4,5,6),TwoDArray<int>(5,7,9)};
  for (int i=0;i<3;i++) {
    EXPECT_EQ(iArray[i].getNumRows(),i+3);
    EXPECT_EQ(iArray[i].getNumCols(),2*i+3);
    EXPECT_EQ(iArray[i].access(i,i),3*i+3);
  }

  for (int i=0;i<100;i++) {
    TwoDArray<int>* iArr = new TwoDArray<int>(i+1,i+1,0);
    EXPECT_EQ(iArr->getNumRows(),i+1);
    EXPECT_EQ(iArr->getNumCols(),i+1);
    EXPECT_EQ(iArr->access(i,i),0);
    delete iArr;
  }

  TwoDArray<double> dArray[3]={TwoDArray<double>(3,3,0.3),TwoDArray<double>(4,5,0.3),TwoDArray<double>(5,7,0.3)};
  for (int i=0;i<3;i++) {
    EXPECT_EQ(dArray[i].getNumRows(),i+3);
    EXPECT_EQ(dArray[i].getNumCols(),2*i+3);
    EXPECT_EQ(dArray[i].access(i,i),0.3);
  }

  for (int i=0;i<100;i++) {
    TwoDArray<double>* dArr = new TwoDArray<double>(i+1,i+1,0.0);
    EXPECT_EQ(dArr->getNumRows(),i+1);
    EXPECT_EQ(dArr->getNumCols(),i+1);
    EXPECT_EQ(dArr->access(i,i),0.0);
    delete dArr;
  }  

  TwoDArray<string> sArray[3]={TwoDArray<string>(3,3,"gtest"),TwoDArray<string>(4,5,"gtest"),TwoDArray<string>(5,7,"gtest")};
  for (int i=0;i<3;i++) {
    EXPECT_EQ(sArray[i].getNumRows(),i+3);
    EXPECT_EQ(sArray[i].getNumCols(),2*i+3);
    EXPECT_EQ(sArray[i].access(i,i),"gtest");
  }

  for (int i=0;i<100;i++) {
    TwoDArray<string>* sArr = new TwoDArray<string>(i+1,i+1,"");
    EXPECT_EQ(sArr->getNumRows(),i+1);
    EXPECT_EQ(sArr->getNumCols(),i+1);
    EXPECT_EQ(sArr->access(i,i),"");
    delete sArr;
  }
}

TEST(TwoDArrayTest,insert) {
  TwoDArray<int>* iArr = new TwoDArray<int>(50,100,0);
  
  for (int i=0; i<25; i++) {
    iArr->insert(i,2*i,7*i);
  }

  for (int i=0; i<5; i++) {
    EXPECT_EQ(iArr->access(i,2*i),7*i);
    EXPECT_EQ(iArr->access(25+i,50+2*i),0);
  }
  
  iArr->insert(4,10,36);
  iArr->insert(0,0,999);
  EXPECT_EQ(iArr->access(4,10),36);
  EXPECT_EQ(iArr->access(0,0),999);

  delete iArr;

  TwoDArray<int> iArray[3]={TwoDArray<int>(3,3,3),TwoDArray<int>(4,5,6),TwoDArray<int>(5,7,0)};
  for (int i=0;i<3;i++) {
    iArray[i].insert(i,i,100);
    EXPECT_EQ(iArray[i].access(i,i),100);
  }

  TwoDArray<double>* dArr = new TwoDArray<double>(50,100,2.71828);
  
  for (int i=0; i<25; i++) {
    dArr->insert(i,2*i,3.14159);
  }

  for (int i=0; i<25; i++) {
    EXPECT_EQ(dArr->access(i,2*i),3.14159);
    EXPECT_EQ(dArr->access(25+i,50+2*i),2.71828);
  }

  dArr->insert(4,10,36.3636);
  dArr->insert(0,0,999.99);
  EXPECT_EQ(dArr->access(4,10),36.3636);
  EXPECT_EQ(dArr->access(0,0),999.99);

  delete dArr;

  TwoDArray<string>* sArr = new TwoDArray<string>(50,100,"");
  
  for (int i=0; i<25; i++) {
    sArr->insert(i,2*i,"C++");
  }

  for (int i=0; i<25; i++) {
    EXPECT_EQ(sArr->access(i,2*i),"C++");
    EXPECT_EQ(sArr->access(25+i,50+2*i),"");
  }

  sArr->insert(2,4,"GitHub");
  sArr->insert(0,0,"Ruby");
  EXPECT_EQ(sArr->access(2,4),"GitHub");
  EXPECT_EQ(sArr->access(0,0),"Ruby");

  delete sArr;
}

TEST(TwoDArrayTest,access) {
  
  TwoDArray<int>* iArr = new TwoDArray<int>(150,100,41);

  for (int i=0; i<25; i++) {
    EXPECT_EQ(iArr->access(i,2*i),41);
  }
  delete iArr;

  TwoDArray<int> iArray[3]={TwoDArray<int>(3,3,3),TwoDArray<int>(4,5,6),TwoDArray<int>(5,7,9)};
  for (int i=0;i<3;i++) {
    EXPECT_EQ(iArray[i].access(i,i),3*i+3);
  }

  TwoDArray<double>* dArr = new TwoDArray<double>(150,100,1.414);

  for (int i=0; i<25; i++) {
    EXPECT_EQ(dArr->access(i,2*i),1.414);
  }
  delete dArr;
  
  TwoDArray<string>* sArr = new TwoDArray<string>(150,100,"Busoni");

  for (int i=0; i<25; i++) {
    EXPECT_EQ(sArr->access(i,2*i),"Busoni");
  }
  delete sArr;
}

TEST(TwoDArrayTest,remove) {
  
  TwoDArray<int>* iArr = new TwoDArray<int>(150,100,0);

  for (int i=0; i<25; i++) {
    EXPECT_EQ(iArr->access(i,2*i),0);
  }
 
  for (int i=0; i<25; i++) {
    iArr->insert(2*i,4*i,99);
    iArr->insert(2*i+1,3,286);
    EXPECT_EQ(iArr->access(2*i,4*i),99);
    EXPECT_EQ(iArr->access(2*i+1,3),286);
    iArr->remove(2*i,4*i);
    iArr->remove(2*i+1,3);
    EXPECT_EQ(iArr->access(2*i,4*i),0);
    EXPECT_EQ(iArr->access(2*i+1,3),0);
  }
  delete iArr;
 
  TwoDArray<int> iArray[3]={TwoDArray<int>(3,3,3),TwoDArray<int>(4,5,6),TwoDArray<int>(5,7,9)};
  for (int i=0;i<3;i++) {
    iArray[i].insert(2,2,2);
    EXPECT_EQ(iArray[i].access(2,2),2);
    iArray[i].remove(2,2);
    EXPECT_EQ(iArray[i].access(2,2),3*i+3);
  }

  TwoDArray<double>* dArr = new TwoDArray<double>(150,100,0);

  for (int i=0; i<25; i++) {
    EXPECT_EQ(dArr->access(i,2*i),0);
  }
 
  for (int i=0; i<25; i++) {
    dArr->insert(2*i,4*i,3.33);
    dArr->insert(2*i+1,3,4.75);
    EXPECT_EQ(dArr->access(2*i,4*i),3.33);
    EXPECT_EQ(dArr->access(2*i+1,3),4.75);
    dArr->remove(2*i,4*i);
    dArr->remove(2*i+1,3);
    EXPECT_EQ(dArr->access(2*i,4*i),0);
    EXPECT_EQ(dArr->access(2*i+1,3),0);
  }
  delete dArr;

  TwoDArray<string>* sArr = new TwoDArray<string>(150,100,"");

  for (int i=0; i<25; i++) {
    EXPECT_EQ(sArr->access(i,2*i),"");
  }
 
  for (int i=0; i<25; i++) {
    sArr->insert(2*i,4*i,"Danny");
    sArr->insert(2*i+1,3,"Boy");
    EXPECT_EQ(sArr->access(2*i,4*i),"Danny");
    EXPECT_EQ(sArr->access(2*i+1,3),"Boy");
    sArr->remove(2*i,4*i);
    sArr->remove(2*i+1,3);
    EXPECT_EQ(sArr->access(2*i,4*i),"");
    EXPECT_EQ(sArr->access(2*i+1,3),"");
  }
  delete sArr;
}

// the Google test below for the print method is just testing if the print method returns without errors.  if i have time later, i will redirect output to a file and test this method properly.

TEST(TwoDArrayTest,print) {

  TwoDArray<int>* iArr = new TwoDArray<int>(10,10,0);
  iArr->insert(1,1,5);
  iArr->insert(2,4,9);
  iArr->print();
  delete iArr;

  TwoDArray<double>* dArr = new TwoDArray<double>(4,8,3.45);
  dArr->insert(3,6,2.22);
  dArr->print();
  delete dArr;

  TwoDArray<string>* sArr = new TwoDArray<string>(6,12,"moo");
  sArr->insert(1,2,"oink");
  sArr->print();
  delete sArr;

}

TEST(TwoDArrayTest,getNumRows) {

  TwoDArray<int>* iArr = new TwoDArray<int>(150,100,0);
  EXPECT_EQ(iArr->getNumRows(),150);
  delete iArr;
  
  TwoDArray<int>* iArr2 = new TwoDArray<int>(24,92,55);
  EXPECT_EQ(iArr2->getNumRows(),24);
  delete iArr2;

  TwoDArray<int> iArray[3]={TwoDArray<int>(3,3,3),TwoDArray<int>(4,5,6),TwoDArray<int>(5,7,0)};
  for (int i=0;i<3;i++) {
    EXPECT_EQ(iArray[i].getNumRows(),i+3);
  }
 
  TwoDArray<double>* dArr = new TwoDArray<double>(150,100,99.45);
  EXPECT_EQ(dArr->getNumRows(),150);
  delete dArr;
 
  TwoDArray<double>* dArr2 = new TwoDArray<double>(24,92,-4.75);
  EXPECT_EQ(dArr->getNumRows(),24);
  delete dArr;
 
  TwoDArray<string>* sArr = new TwoDArray<string>(150,100,"sparse");
  EXPECT_EQ(sArr->getNumRows(),150);
  delete sArr;

  TwoDArray<string>* sArr2 = new TwoDArray<string>(24,92,"song");
  EXPECT_EQ(sArr2->getNumRows(),24);
  delete sArr2;
}

TEST(TwoDArrayTest,getNumCols) {

  TwoDArray<int>* iArr = new TwoDArray<int>(150,100,0);
  EXPECT_EQ(iArr->getNumCols(),100);
  delete iArr;

  TwoDArray<int>* iArr2 = new TwoDArray<int>(65,60,5);
  EXPECT_EQ(iArr2->getNumCols(),60);
  delete iArr2;

  TwoDArray<int> iArray[3]={TwoDArray<int>(3,3,3),TwoDArray<int>(4,5,6),TwoDArray<int>(5,7,0)};
  for (int i=0;i<3;i++) {
    EXPECT_EQ(iArray[i].getNumCols(),2*i+3);
  }

  TwoDArray<double>* dArr = new TwoDArray<double>(150,100,99.45);
  EXPECT_EQ(dArr->getNumCols(),100);
  delete dArr;

  TwoDArray<double>* dArr2 = new TwoDArray<double>(1,33,0.75);
  EXPECT_EQ(dArr2->getNumCols(),33);
  delete dArr2;

  TwoDArray<string>* sArr = new TwoDArray<string>(150,100,"sparse");
  EXPECT_EQ(sArr->getNumCols(),100);
  delete sArr; 

  TwoDArray<string>* sArr2 = new TwoDArray<string>(55,9,"sleep");
  EXPECT_EQ(sArr2->getNumCols(),9);
  delete sArr2;
}

