#include "fh.h"
#include "huffman.h"
#include <fstream>
#include <chrono>
#include<iterator>

using namespace std;
using namespace std::chrono;

int main()
{
    CodeTree* ct_shf;
    CodeTree* ct_huff;
    char *c;
    std::ifstream fin("input.dat");
    std::ofstream fout_encode_huffman("huffman.dat");
    std::ofstream fout_encode_shannon_fano("shf.dat");
    std::ofstream fout_decode_huffman("huffman_decode.dat");
    std::ofstream fout_decode_shannon_fano("shf_decode.dat");
    c = new char[MAX_INPUT_LEN];
    char *_encode_shf, *_decode_shf;
    char *_encode_huff, *_decode_huff;
    long long int i = 1;
    c[0] = fin.get();
    while(fin.peek()!=EOF)
    {
	c[i] = fin.get();
        i++;
    }
    ct_shf = fanno_shannon(c);
    ct_huff = huffman(c);

    auto begin_enc_shf = std::chrono::high_resolution_clock::now();
    _encode_shf = encode(ct_shf, c);
    auto end_enc_shf = std::chrono::high_resolution_clock::now();
    
    auto begin_dec_shf = std::chrono::high_resolution_clock::now();
    _decode_shf = decode(ct_shf, _encode_shf);
    auto end_dec_shf = std::chrono::high_resolution_clock::now();
    
    auto begin_enc_huff = std::chrono::high_resolution_clock::now();
    _encode_huff = encode(ct_huff, c);
    auto end_enc_huff = std::chrono::high_resolution_clock::now();
    
    auto begin_dec_huff = std::chrono::high_resolution_clock::now();
    _decode_huff = decode(ct_huff, _encode_huff);
    auto end_dec_huff = std::chrono::high_resolution_clock::now();
    std::cout << "Algorithm speed (in microseconds):" << std::endl;
    std::cout << "Encoding sh_f: " << std::chrono::duration_cast<std::chrono::microseconds>(end_enc_shf - begin_enc_shf).count() << std::endl;
    std::cout << "Decoding sh_f: " << std::chrono::duration_cast<std::chrono::microseconds>(end_dec_shf - begin_dec_shf).count() << std::endl;
    std::cout << "Encoding huff: " << std::chrono::duration_cast<std::chrono::microseconds>(end_enc_huff - begin_enc_huff).count() << std::endl;
    std::cout << "Decoding huff: " << std::chrono::duration_cast<std::chrono::microseconds>(end_dec_huff - begin_dec_huff).count() << std::endl;
    fout_encode_shannon_fano << _encode_shf << std::endl;
    fout_decode_shannon_fano << _decode_shf << std::endl;
    fout_encode_huffman << _encode_huff << std::endl;
    fout_decode_huffman << _decode_huff << std::endl;
    destroy(ct_shf);
    destroy(ct_huff);
    delete[] c;
    fout_encode_huffman.close();
    fout_encode_shannon_fano.close();
    fout_decode_huffman.close();
    fout_decode_shannon_fano.close();
    fin.close();
    return 0;
}

