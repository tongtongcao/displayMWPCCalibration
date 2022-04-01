#include <vector>
#include <string>
#include <sstream>
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TF1.h"
#include "TROOT.h"
#include "TLegend.h"
using namespace std;

void compare(){
 gStyle->SetOptStat(0000);
 gStyle->SetOptFit(0000);
 gROOT->ForceStyle();

 string str[7]={"3157","3397","3399","3779","4142","4272","4273"};
 TFile *file[7];
 TTree *tree[7];

 double pddC2YL[7][16],pddC2YR[7][16],pddC3YL[7][16],pddC3YR[7][16],pddC4YL[7][16],pddC4YR[7][16];
 double pddC2XL[7][56],pddC2XR[7][56],pddC3XL[7][64],pddC3XR[7][64],pddC4XL[7][72],pddC4XR[7][72];
 double errC2YL[7][16],errC2YR[7][16],errC3YL[7][16],errC3YR[7][16],errC4YL[7][16],errC4YR[7][16];
 double errC2XL[7][56],errC2XR[7][56],errC3XL[7][64],errC3XR[7][64],errC4XL[7][72],errC4XR[7][72];


 ostringstream sstr;
 for(int i=0;i<7;i++){
  sstr<<"/home/caot/trek-e36/analysis/MWPC/pedestal/Run"<<str[i]<<"/pedestal.root";
cout<<sstr.str()<<endl;
  file[i]=new TFile(sstr.str().c_str());
  sstr.str("");
  tree[i]=(TTree*)file[i]->Get("pedestal");

  tree[i]->SetBranchAddress("pddC2XL",pddC2XL[i]);
  tree[i]->SetBranchAddress("pddC2XR",pddC2XR[i]);
  tree[i]->SetBranchAddress("pddC3XL",pddC3XL[i]);
  tree[i]->SetBranchAddress("pddC3XR",pddC3XR[i]);
  tree[i]->SetBranchAddress("pddC4XL",pddC4XL[i]);
  tree[i]->SetBranchAddress("pddC4XR",pddC4XR[i]);

  tree[i]->SetBranchAddress("pddC2YL",pddC2YL[i]);
  tree[i]->SetBranchAddress("pddC2YR",pddC2YR[i]);
  tree[i]->SetBranchAddress("pddC3YL",pddC3YL[i]);
  tree[i]->SetBranchAddress("pddC3YR",pddC3YR[i]);
  tree[i]->SetBranchAddress("pddC4YL",pddC4YL[i]);
  tree[i]->SetBranchAddress("pddC4YR",pddC4YR[i]);

  tree[i]->SetBranchAddress("errC2XL",errC2XL[i]);
  tree[i]->SetBranchAddress("errC2XR",errC2XR[i]);
  tree[i]->SetBranchAddress("errC3XL",errC3XL[i]);
  tree[i]->SetBranchAddress("errC3XR",errC3XR[i]);
  tree[i]->SetBranchAddress("errC4XL",errC4XL[i]);
  tree[i]->SetBranchAddress("errC4XR",errC4XR[i]);

  tree[i]->SetBranchAddress("errC2YL",errC2YL[i]);
  tree[i]->SetBranchAddress("errC2YR",errC2YR[i]);
  tree[i]->SetBranchAddress("errC3YL",errC3YL[i]);
  tree[i]->SetBranchAddress("errC3YR",errC3YR[i]);
  tree[i]->SetBranchAddress("errC4YL",errC4YL[i]);
  tree[i]->SetBranchAddress("errC4YR",errC4YR[i]);

  tree[i]->GetEntry(0);
 } 

 TH1D *hist_pddC2YL[7],*hist_pddC2YR[7],*hist_pddC3YL[7],*hist_pddC3YR[7],*hist_pddC4YL[7],*hist_pddC4YR[7];
 TH1D *hist_pddC2XL[7],*hist_pddC2XR[7],*hist_pddC3XL[7],*hist_pddC3XR[7],*hist_pddC4XL[7],*hist_pddC4XR[7];
 ostringstream name,title;
 for(int i=0;i<7;i++){
  name<<"pedestal of MwpcC2YL for Run"<<str[i];
  title<<"pedestal of MwpcC2YL;Strip;Pedestal";
  hist_pddC2YL[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_pddC2YL[i]->SetBinContent(j+1,pddC2YL[i][j]);
   hist_pddC2YL[i]->SetBinError(j+1,errC2YL[i][j]);
  }

  name<<"pedestal of MwpcC2YR for Run"<<str[i];
  title<<"pedestal of MwpcC2YR;Strip;Pedestal";
  hist_pddC2YR[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_pddC2YR[i]->SetBinContent(j+1,pddC2YR[i][j]);
   hist_pddC2YR[i]->SetBinError(j+1,errC2YR[i][j]);
  }

  name<<"pedestal of MwpcC3YL for Run"<<str[i];
  title<<"pedestal of MwpcC3YL;Strip;Pedestal";
  hist_pddC3YL[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_pddC3YL[i]->SetBinContent(j+1,pddC3YL[i][j]);
   hist_pddC3YL[i]->SetBinError(j+1,errC3YL[i][j]);
  }

  name<<"pedestal of MwpcC3YR for Run"<<str[i];
  title<<"pedestal of MwpcC3YR;Strip;Pedestal";
  hist_pddC3YR[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_pddC3YR[i]->SetBinContent(j+1,pddC3YR[i][j]);
   hist_pddC3YR[i]->SetBinError(j+1,errC3YR[i][j]);
  }


  name<<"pedestal of MwpcC4YL for Run"<<str[i];
  title<<"pedestal of MwpcC4YL;Strip;Pedestal";
  hist_pddC4YL[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_pddC4YL[i]->SetBinContent(j+1,pddC4YL[i][j]);
   hist_pddC4YL[i]->SetBinError(j+1,errC4YL[i][j]);
  }

  name<<"pedestal of MwpcC4YR for Run"<<str[i];
  title<<"pedestal of MwpcC4YR;Strip;Pedestal";
  hist_pddC4YR[i]=new TH1D(name.str().c_str(),title.str().c_str(),16,-0.5,15.5);
  name.str("");
  title.str("");
  for(int j=0;j<16;j++){
   hist_pddC4YR[i]->SetBinContent(j+1,pddC4YR[i][j]);
   hist_pddC4YR[i]->SetBinError(j+1,errC4YR[i][j]);
  }

  name<<"pedestal of MwpcC2XL for Run"<<str[i];
  title<<"pedestal of MwpcC2XL;Strip;Pedestal";
  hist_pddC2XL[i]=new TH1D(name.str().c_str(),title.str().c_str(),56,-0.5,55.5);
  name.str("");
  title.str("");
  for(int j=0;j<56;j++){
   hist_pddC2XL[i]->SetBinContent(j+1,pddC2XL[i][j]);
   hist_pddC2XL[i]->SetBinError(j+1,errC2XL[i][j]);
  }

  name<<"pedestal of MwpcC2XR for Run"<<str[i];
  title<<"pedestal of MwpcC2XR;Strip;Pedestal";
  hist_pddC2XR[i]=new TH1D(name.str().c_str(),title.str().c_str(),56,-0.5,55.5);
  name.str("");
  title.str("");
  for(int j=0;j<56;j++){
   hist_pddC2XR[i]->SetBinContent(j+1,pddC2XR[i][j]);
   hist_pddC2XR[i]->SetBinError(j+1,errC2XR[i][j]);
  }

  name<<"pedestal of MwpcC3XL for Run"<<str[i];
  title<<"pedestal of MwpcC3XL;Strip;Pedestal";
  hist_pddC3XL[i]=new TH1D(name.str().c_str(),title.str().c_str(),64,-0.5,63.5);
  name.str("");
  title.str("");
  for(int j=0;j<64;j++){
   hist_pddC3XL[i]->SetBinContent(j+1,pddC3XL[i][j]);
   hist_pddC3XL[i]->SetBinError(j+1,errC3XL[i][j]);
  }

  name<<"pedestal of MwpcC3XR for Run"<<str[i];
  title<<"pedestal of MwpcC3XR;Strip;Pedestal";
  hist_pddC3XR[i]=new TH1D(name.str().c_str(),title.str().c_str(),64,-0.5,63.5);
  name.str("");
  title.str("");
  for(int j=0;j<64;j++){
   hist_pddC3XR[i]->SetBinContent(j+1,pddC3XR[i][j]);
   hist_pddC3XR[i]->SetBinError(j+1,errC3XR[i][j]);
  }

  name<<"pedestal of MwpcC4XL for Run"<<str[i];
  title<<"pedestal of MwpcC4XL;Strip;Pedestal";
  hist_pddC4XL[i]=new TH1D(name.str().c_str(),title.str().c_str(),72,-0.5,71.5);
  name.str("");
  title.str("");
  for(int j=0;j<72;j++){
   hist_pddC4XL[i]->SetBinContent(j+1,pddC4XL[i][j]);
   hist_pddC4XL[i]->SetBinError(j+1,errC4XL[i][j]);
  }

  name<<"pedestal of MwpcC4XR for Run"<<str[i];
  title<<"pedestal of MwpcC4XR;Strip;Pedestal";
  hist_pddC4XR[i]=new TH1D(name.str().c_str(),title.str().c_str(),72,-0.5,71.5);
  name.str("");
  title.str("");
  for(int j=0;j<72;j++){
   hist_pddC4XR[i]->SetBinContent(j+1,pddC4XR[i][j]);
   hist_pddC4XR[i]->SetBinError(j+1,errC4XR[i][j]);
  }
 }

 TLegend *legend=new TLegend(0.7,0.6,0.9,0.9);
 for(int i=0;i<7;i++){
  sstr<<"Run"<<str[i];
  legend->AddEntry(hist_pddC2XL[i],sstr.str().c_str(),"l");
  sstr.str("");
 }

 TCanvas *canv_pdd=new TCanvas("pedestal of MWPCs","pedestal of MWPCs",1200,900);
 canv_pdd->Divide(4,3);
 canv_pdd->cd(1);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC2XL[i]->SetMinimum(0);
   hist_pddC2XL[i]->SetMaximum(200);
   hist_pddC2XL[i]->SetLineColor(i+2);
   hist_pddC2XL[i]->SetMarkerColor(i+2);
   hist_pddC2XL[i]->Draw();
  }
  else{
   hist_pddC2XL[i]->SetLineColor(i+2);
   hist_pddC2XL[i]->SetMarkerColor(i+2);
   hist_pddC2XL[i]->Draw("same");
  }
 }
 legend->Draw();

 canv_pdd->cd(2);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC2XR[i]->SetMinimum(0);
   hist_pddC2XR[i]->SetMaximum(200);
   hist_pddC2XR[i]->SetLineColor(i+2);
   hist_pddC2XR[i]->SetMarkerColor(i+2);
   hist_pddC2XR[i]->Draw();
  }
  else{
   hist_pddC2XR[i]->SetLineColor(i+2);
   hist_pddC2XR[i]->SetMarkerColor(i+2);
   hist_pddC2XR[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_pdd->cd(3);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC2YL[i]->SetMinimum(0);
   hist_pddC2YL[i]->SetMaximum(200);
   hist_pddC2YL[i]->SetLineColor(i+2);
   hist_pddC2YL[i]->SetMarkerColor(i+2);
   hist_pddC2YL[i]->Draw();
  }
  else{
   hist_pddC2YL[i]->SetLineColor(i+2);
   hist_pddC2YL[i]->SetMarkerColor(i+2);
   hist_pddC2YL[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_pdd->cd(4);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC2YR[i]->SetMinimum(0);
   hist_pddC2YR[i]->SetMaximum(200);
   hist_pddC2YR[i]->SetLineColor(i+2);
   hist_pddC2YR[i]->SetMarkerColor(i+2);
   hist_pddC2YR[i]->Draw();
  }
  else{
   hist_pddC2YR[i]->SetLineColor(i+2);
   hist_pddC2YR[i]->SetMarkerColor(i+2);
   hist_pddC2YR[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_pdd->cd(5);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC3XL[i]->SetMinimum(0);
   hist_pddC3XL[i]->SetMaximum(200);
   hist_pddC3XL[i]->SetLineColor(i+2);
   hist_pddC3XL[i]->SetMarkerColor(i+2);
   hist_pddC3XL[i]->Draw();
  }
  else{
   hist_pddC3XL[i]->SetLineColor(i+2);
   hist_pddC3XL[i]->SetMarkerColor(i+2);
   hist_pddC3XL[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_pdd->cd(6);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC3XR[i]->SetMinimum(0);
   hist_pddC3XR[i]->SetMaximum(200);
   hist_pddC3XR[i]->SetLineColor(i+2);
   hist_pddC3XR[i]->SetMarkerColor(i+2);
   hist_pddC3XR[i]->Draw();
  }
  else{
   hist_pddC3XR[i]->SetLineColor(i+2);
   hist_pddC3XR[i]->SetMarkerColor(i+2);
   hist_pddC3XR[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_pdd->cd(7);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC3YL[i]->SetMinimum(0);
   hist_pddC3YL[i]->SetMaximum(200);
   hist_pddC3YL[i]->SetLineColor(i+2);
   hist_pddC3YL[i]->SetMarkerColor(i+2);
   hist_pddC3YL[i]->Draw();
  }
  else{
   hist_pddC3YL[i]->SetLineColor(i+2);
   hist_pddC3YL[i]->SetMarkerColor(i+2);
   hist_pddC3YL[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_pdd->cd(8);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC3YR[i]->SetMinimum(0);
   hist_pddC3YR[i]->SetMaximum(200);
   hist_pddC3YR[i]->SetLineColor(i+2);
   hist_pddC3YR[i]->SetMarkerColor(i+2);
   hist_pddC3YR[i]->Draw();
  }
  else{
   hist_pddC3YR[i]->SetLineColor(i+2);
   hist_pddC3YR[i]->SetMarkerColor(i+2);
   hist_pddC3YR[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_pdd->cd(9);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC4XL[i]->SetMinimum(0);
   hist_pddC4XL[i]->SetMaximum(200);
   hist_pddC4XL[i]->SetLineColor(i+2);
   hist_pddC4XL[i]->SetMarkerColor(i+2);
   hist_pddC4XL[i]->Draw();
  }
  else{
   hist_pddC4XL[i]->SetLineColor(i+2);
   hist_pddC4XL[i]->SetMarkerColor(i+2);
   hist_pddC4XL[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_pdd->cd(10);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC4XR[i]->SetMinimum(0);
   hist_pddC4XR[i]->SetMaximum(200);
   hist_pddC4XR[i]->SetLineColor(i+2);
   hist_pddC4XR[i]->SetMarkerColor(i+2);
   hist_pddC4XR[i]->Draw();
  }
  else{
   hist_pddC4XR[i]->SetLineColor(i+2);
   hist_pddC4XR[i]->SetMarkerColor(i+2);
   hist_pddC4XR[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_pdd->cd(11);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC4YL[i]->SetMinimum(0);
   hist_pddC4YL[i]->SetMaximum(200);
   hist_pddC4YL[i]->SetLineColor(i+2);
   hist_pddC4YL[i]->SetMarkerColor(i+2);
   hist_pddC4YL[i]->Draw();
  }
  else{
   hist_pddC4YL[i]->SetLineColor(i+2);
   hist_pddC4YL[i]->SetMarkerColor(i+2);
   hist_pddC4YL[i]->Draw("same");
  }
 }
 //legend->Draw();

 canv_pdd->cd(12);
 for(int i=0;i<7;i++){
  if(i==0){
   hist_pddC4YR[i]->SetMinimum(0);
   hist_pddC4YR[i]->SetMaximum(200);
   hist_pddC4YR[i]->SetLineColor(i+2);
   hist_pddC4YR[i]->SetMarkerColor(i+2);
   hist_pddC4YR[i]->Draw();
  }
  else{
   hist_pddC4YR[i]->SetLineColor(i+2);
   hist_pddC4YR[i]->SetMarkerColor(i+2);
   hist_pddC4YR[i]->Draw("same");
  }
 }
 //legend->Draw();
 canv_pdd->SaveAs("pedestal vs strip.pdf");
}

