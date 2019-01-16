// example code to run 2015 mono-Higgs resolved selections on signal (EXO-16-012) compute signal efficiency

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <TH1D.h>
#include <TFile.h>
#include "untuplizer.h"
#include <TClonesArray.h>
#include <TLorentzVector.h>
#define overlap_resolved_xAna_cxx
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>


using namespace std;
void overlap_resolved_xAna(){
    
    TCanvas *overlapC = new TCanvas("overlapC","overlapC", 800, 600);
    //overlapC->Divide(1,8);
    TLegend *leg = new TLegend(0.6,0.5,0.8,0.7);
    leg->SetBorderSize(0);
    leg->SetTextSize(0.017);
    string name[] = {"MZp-100_MChi-1","MZp-100_MChi2-1_MChi1-0p1_ctau-1000","MZp-100_MChi2-1_MChi1-0p1_ctau-100","MZp-100_MChi2-1_MChi1-0p1_ctau-1","MZp-100_MChi2-1_MChi1-0p5_ctau-1","MZp-100_MChi2-1_MChi1-0p8_ctau-100000"};
    TFile f("Zp100.root");
    
    int nhist = 6;
    TH1F *h_goodVtx[nhist];
    TH1F *h_pfMet[nhist];
    TH1F *h_pfMetPhi[nhist];
    TH1F *h_nEle[nhist];
    TH1F *h_nMu[nhist];
    TH1F *h_nTau[nhist];
    TH1F *h_nGoodTHINJets[nhist];
    TH1F *h_nGoodTHINBJets[nhist];
    
    
    int color[]={1,2,3,4,5,6};
    
    
    //overlap number of good vertex histograms
    string pdfName1 = "mzp100_2.pdf";
    overlapC->Print((pdfName1+"[").data());
    for(int i=0;i<nhist;i++){
        h_goodVtx[i] = (TH1F*)f.Get(Form("goodVtxhist%d",i));
        leg->AddEntry(h_goodVtx[i],Form("%s",name[i].data())); //%s=string %d=int %f=float
        h_goodVtx[i]->SetLineColor(color[i]);
        h_goodVtx[i]->SetStats(0);
    }
    h_goodVtx[0]->Draw("hist");
    for(int j=1;j<nhist;j++){
        h_goodVtx[j]->Draw("histsame");
    }
    leg->Draw();
    overlapC->Print(pdfName1.data());
    
    //overlap pfMet Distribution
    leg->Clear();
    for(int i=0;i<nhist;i++){
        h_pfMet[i] = (TH1F*)f.Get(Form("pfMethist%d",i));
        leg->AddEntry(h_pfMet[i],Form("%s",name[i].data()));
        h_pfMet[i]->SetLineColor(color[i]);
        h_pfMet[i]->SetStats(0);
    }
    h_pfMet[0]->Draw("hist");
    for(int j=1;j<nhist;j++){
        h_pfMet[j]->Draw("histsame");
    }
    leg->Draw();
    overlapC->Print(pdfName1.data());
    
    //overlap pfMetPhi Distribution
    leg->Clear();
    for(int i=0;i<nhist;i++){
        h_pfMetPhi[i] = (TH1F*)f.Get(Form("pfMetPhihist%d",i));
        leg->AddEntry(h_pfMetPhi[i],Form("%s",name[i].data()));
        h_pfMetPhi[i]->SetLineColor(color[i]);
        h_pfMetPhi[i]->SetStats(0);
    }
    h_pfMetPhi[0]->Draw("hist");
    for(int j=1;j<nhist;j++){
        h_pfMetPhi[j]->Draw("histsame");
    }
    leg->Draw();
    overlapC->Print(pdfName1.data());
    
    
    //overlap Number of Electrons
    leg->Clear();
    for(int i=0;i<nhist;i++){
        h_nEle[i] = (TH1F*)f.Get(Form("Elehist%d",i));
        leg->AddEntry(h_nEle[i],Form("%s",name[i].data()));
        h_nEle[i]->SetLineColor(color[i]);
        h_nEle[i]->SetStats(0);
    }
    h_nEle[0]->Draw("hist");
    for(int j=1;j<nhist;j++){
        h_nEle[j]->Draw("histsame");
    }
    leg->Draw();
    overlapC->Print(pdfName1.data());
    
    //overlap Number of Muons
    leg->Clear();
    for(int i=0;i<nhist;i++){
        h_nMu[i] = (TH1F*)f.Get(Form("Muhist%d",i));
        leg->AddEntry(h_nMu[i],Form("%s",name[i].data()));
        h_nMu[i]->SetLineColor(color[i]);
        h_nMu[i]->SetStats(0);
    }
    h_nMu[0]->Draw("hist");
    for(int j=1;j<nhist;j++){
        h_nMu[j]->Draw("histsame");
    }
    leg->Draw();
    overlapC->Print(pdfName1.data());
    
    //overlap Number of Taus
    leg->Clear();
    for(int i=0;i<nhist;i++){
        h_nTau[i] = (TH1F*)f.Get(Form("Tauhist%d",i));
        leg->AddEntry(h_nTau[i],Form("%s",name[i].data()));
        h_nTau[i]->SetLineColor(color[i]);
        h_nTau[i]->SetStats(0);
    }
    h_nTau[0]->Draw("hist");
    for(int j=1;j<nhist;j++){
        h_nTau[j]->Draw("histsame");
    }
    leg->Draw();
    overlapC->Print(pdfName1.data());
    
    //overlap Number of Good Thin Jets
    leg->Clear();
    for(int i=0;i<nhist;i++){
        h_nGoodTHINJets[i] = (TH1F*)f.Get(Form("nGoodTHINJetshist%d",i));
        leg->AddEntry(h_nGoodTHINJets[i],Form("%s",name[i].data()));
        h_nGoodTHINJets[i]->SetLineColor(color[i]);
        h_nGoodTHINJets[i]->SetStats(0);
    }
    h_nGoodTHINJets[0]->Draw("hist");
    for(int j=1;j<nhist;j++){
        h_nGoodTHINJets[j]->Draw("histsame");
    }
    leg->Draw();
    overlapC->Print(pdfName1.data());
    
    //overlap Number of Good Thin b Jets
    leg->Clear();
    for(int i=0;i<nhist;i++){
        h_nGoodTHINBJets[i] = (TH1F*)f.Get(Form("nGoodTHINBJetshist%d",i));
        leg->AddEntry(h_nGoodTHINBJets[i],Form("%s",name[i].data()));
        h_nGoodTHINBJets[i]->SetLineColor(color[i]);
        h_nGoodTHINBJets[i]->SetStats(0);
    }
    h_nGoodTHINBJets[0]->Draw("hist");
    for(int j=1;j<nhist;j++){
        h_nGoodTHINBJets[j]->Draw("histsame");
    }
    leg->Draw();
    overlapC->Print(pdfName1.data());
    overlapC->Print((pdfName1+"]").data());
    

}
