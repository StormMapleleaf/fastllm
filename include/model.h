//
// Created by huangyuyang on 6/20/23.
//

#ifndef FASTLLM_MODEL_H
#define FASTLLM_MODEL_H

#include "basellm.h"
#include "bert.h"
#include "xlmroberta.h"

namespace fastllm {
    std::unique_ptr<BertModel> CreateEmbeddingModelFromFile(const std::string &fileName);

    std::unique_ptr<basellm> CreateLLMModelFromFile(const std::string &fileName);

    std::unique_ptr<basellm> CreateEmptyLLMModel(const std::string &modelType);

    std::unique_ptr<basellm> CreateLLMModelFromHF(const std::string &modelPath, 
                                                    DataType linearDataType, 
                                                    int groupCnt = -1,
                                                    bool skipTokenizer = false,
                                                    const std::string &modelConfig = "",
                                                    const std::string &loraPath = "",
                                                    bool weightOnly = false, 
                                                    bool useMoeDataType = false, 
                                                    DataType moeDataType = DataType::FLOAT32, 
                                                    int moeGroupCnt = -1);
    
    void ExportLLMModelFromHF(const std::string &modelPath, 
                            DataType linearDataType, 
                            int groupCnt, 
                            const std::string &exportPath, 
                            const std::string &modelConfig = "",
                            const std::string &loraPath = "", 
                            bool useMoeDataType = false, 
                            DataType moeDataType = DataType::FLOAT32, 
                            int moeGroupCnt = -1);
    
    std::unique_ptr<basellm> CreateLLMTokenizerFromHF(const std::string &modelPath);
}

#endif //FASTLLM_MODEL_H
