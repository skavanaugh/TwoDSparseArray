#include "gtest/gtest.h"
#include "../../include/TwoDArray.h"
using std::string;

TEST(TwoDArrayTest,insert) {
  TwoDArray<int>* iArr = new TwoDArray<int>(50,100,0);
  
  for (int i=0; i<25; i++) {
    iArr->insert(i,2*i,7*i);
  }

  for (int i=0; i<25; i++) {
    EXPECT_EQ(iArr->access(i,2*i),7*i);
    EXPECT_EQ(iArr->access(25+i,50+2*i),0);
  }

  iArr->insert(12,24,36);
  iArr->insert(0,0,999);
  EXPECT_EQ(iArr->access(12,24),36);
  EXPECT_EQ(iArr->access(0,0),999);

  delete iArr;

  TwoDArray<double>* dArr = new TwoDArray<double>(50,100,2.71828);
  
  for (int i=0; i<25; i++) {
    dArr->insert(i,2*i,3.14159);
  }

  for (int i=0; i<25; i++) {
    EXPECT_EQ(dArr->access(i,2*i),3.14159);
    EXPECT_EQ(dArr->access(25+i,50+2*i),2.71828);
  }

  dArr->insert(12,24,36.3636);
  dArr->insert(0,0,999.99);
  EXPECT_EQ(iArr->access(12,24),36.3636);
  EXPECT_EQ(iArr->access(0,0),999.99);

  delete dArr;

  TwoDArray<string>* sArr = new TwoDArray<string>(50,100,"");
  
  for (int i=0; i<25; i++) {
    sArr->insert(i,2*i,"C++");
  }

  for (int i=0; i<25; i++) {
    EXPECT_EQ(sArr->access(i,2*i),"C++");
    EXPECT_EQ(sArr->access(25+i,50+2*i),"");
  }

  sArr->insert(12,24,"GitHub");
  sArr->insert(0,0,"Ruby");
  EXPECT_EQ(sArr->access(12,24),"GitHub");
  EXPECT_EQ(sArr->access(0,0),"Ruby");

  delete sArr;
}

TEST(TwoDArrayTest,access) {
  
  TwoDArray<int>* iArr = new TwoDArray<int>(150,100,41);

  for (int i=0; i<25; i++) {
    EXPECT_EQ(iArr->access(i,2*i),41);
  }
  delete iArr;

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

  TwoDArray<double>* dArr = new TwoDArray<double>(150,100,0);

  for (int i=0; i<25; i++) {
    EXPECT_EQ(dArr->access(i,2*i),0);
  }
 
  for (int i=0; i<25; i++) {
    dArr->insert(2*i,4*i,3.33);
    dArr->insert(2*i+1,3,-4.75);
    EXPECT_EQ(dArr->access(2*i,4*i),3.33);
    EXPECT_EQ(dArr->access(2*i+1,3),-4.75);
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

// no Google test implemented for print method

TEST(TwoDArrayTest,getNumRows) {

  TwoDArray<int>* iArr = new TwoDArray<int>(150,100,0);
  EXPECT_EQ(iArr->getNumRows(),150);
  delete iArr;

  TwoDArray<int>* iArr[10];
  for (int i=0; i<10; i++) {
    iArr[i] = new TwoDArray<int>(2*i+5,4*i+3,0)
    EXPECT_EQ(iArr[i]->getNumRows(),2*i+5);    
  }
  delete [] iArr;

  TwoDArray<double>* dArr = new TwoDArray<double>(150,100,99.45);
  EXPECT_EQ(dArr->getNumRows(),150);
  delete dArr;

  TwoDArray<double>* dArr[10];
  for (int i=0; i<10; i++) {
    dArr[i] = new TwoDArray<double>(2*i+5,4*i+3,3.99)
    EXPECT_EQ(dArr[i]->getNumRows(),2*i+5);    
  }
  delete [] dArr;

  TwoDArray<string>* sArr = new TwoDArray<string>(150,100,"sparse");
  EXPECT_EQ(sArr->getNumRows(),150);
  delete sArr;

  TwoDArray<string>* sArr[10];
  for (int i=0; i<10; i++) {
    sArr[i] = new TwoDArray<string>(2*i+5,4*i+3,"tick tock")
    EXPECT_EQ(sArr[i]->getNumRows(),2*i+5);    
  }
  delete [] sArr;
}


TEST(TwoDArrayTest,remove) {

}
