#include"../Core/datastructure.h"




typedef struct A3D{
    ARR *data;
    unsigned int depth, rows, cols;
    struct A3D *Depth, *Rows, *Cols;
} ARR_TENSOR;

typedef struct A2D{
    ARR *data;
    unsigned int  rows, cols;
    struct A2D *Rows, *Cols;
} ARR_MATRIX;

typedef struct Type_Oftensor{const unsigned int Low,High,Right,Left;}Typetensor;
typedef enum ComputerOperation{XOR,AND,NOR,OR,NOT,NAND}CsOpcode;


ARR_TENSOR *CreateTensor(ARR_TENSOR *PTR,Typetensor Size);
void DestroyTensor(ARR_TENSOR *PTR);
void DestroyTensorDataOnly(ARR_TENSOR *PTR);
void InfoTensor(ARR_TENSOR *TENSOR);
void PrintTensor(ARR_TENSOR *T);

void InsertDataInTensor(VTD *Tensordata,ARR *ARRPTR,ARR_TENSOR *MAINTENSOR);
void DeleteDataInTensor(VTD *Tensordata,ARR *ARRPTR,ARR_TENSOR *MAINTENSOR);
void SearchDataIntensor(VTD *Tensordata,ARR *ARRPTR,ARR_TENSOR *MAINTENSOR);
void ReplaceDataIntensor(VTD *Tensordata,ARR *ARRPTR,ARR_TENSOR *MAINTENSOR);
void ShowPositionOfData(VTD *Tensordata,ARR *ARRPTR,ARR_TENSOR *MAINTENSOR);
void SwapTwoTensor(VTD *Tensordata,VTD *Tensordata2,ARR *ARRPTR,ARR *ARRPTR2,ARR_TENSOR *MAINTENSOR,ARR_TENSOR *MAINTENSOR2);
void CalculateSizeOfTensor(ARR_TENSOR *Tensor);
void SortTensorData(ARR_TENSOR *TENSOR,SORTsEarcHopCode ST);
void CheckWhereIsNullInTensor(ARR_TENSOR *TensorX);
void ReplaceNullWithvalue(ARR_TENSOR *TensorX);


ARR_TENSOR *MultiplyTensor(ARR_TENSOR *TENS1,ARR_TENSOR *TENS2);
ARR_TENSOR *AdditionTensor(ARR_TENSOR *TENS1,ARR_TENSOR *TENS2);
ARR_TENSOR *DivisionTensor(ARR_TENSOR *TENS1,ARR_TENSOR *TENS2);
ARR_TENSOR *SubstractTensor(ARR_TENSOR *TENS1,ARR_TENSOR *TENS2);
ARR_TENSOR *MaxAndMinTensor(ARR_TENSOR *TENS1,ARR_TENSOR *TENS2);
ARR_TENSOR *AvarageTensor(ARR_TENSOR *TENS1,ARR_TENSOR *TENS2);

ARR_TENSOR *CsOperationTensor(ARR_TENSOR *TENS1,ARR_TENSOR *TENS2,CsOpcode Cs);

ARR_TENSOR *CreateSparse0and1Tensor(ARR_TENSOR *TENS,Typetensor Size);
















ARR_TENSOR *CreateTensor(ARR_TENSOR *PTR,Typetensor Size){


}