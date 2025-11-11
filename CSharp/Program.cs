using System;
using System.Collections.Generic;
using System.Numerics;


class Program
{
    static void Main()
    {
        double man = 1e4;        // 만
        double eok = 1e8;        // 억
        double jo = 1e12;        // 조
        double gyeong = 1e16;    // 경
        double hae = 1e20;       // 해
        double ja = 1e24;        // 자
        double yang = 1e28;      // 양
        double gu = 1e32;        // 구
        double gan = 1e36;       // 간
        double jeong = 1e40;     // 정
        double jae = 1e44;       // 재
        double geuk = 1e48;      // 극
        double hanghasa = 1e52;  // 항하사
        double aseunggi = 1e56;  // 아승기
        double nayuta = 1e60;    // 나유타
        double bulgasaui = 1e64; // 불가사의
        double muryangdaesu = 1e68; // 무량대수

        // double 최대값: 약 1.7e308
        double d1 = 1.234e16;
        double d2 = 1.2345e24;
        double d3 = 1.23456e32;
        double d4 = 1.234567e40;
        double d5 = 1.2345678e48;
        double d6 = 1.23456789e56;
        double d7 = 1.234567890123456789e68;
        double d8 = 1.23456e8;

        // decimal 최대값: 약 7.9e28 (7.9양), 그 이상은 할당 불가
        decimal dec1 = 1.23131e28m;
        decimal dec2 = 7.1234567890123456789e28m;

        // BigInteger 최대값: 메모리 한도 내 매우 큰 수 할당 가능
        BigInteger big1 = BigInteger.Parse("1234567890123456789") * BigInteger.Pow(10, 50);
        BigInteger big2 = BigInteger.Parse("1234567890123456789") * BigInteger.Pow(10, 40);
        BigInteger big3 = BigInteger.Parse("999956789123456789012345678912345678912345679123456789123456789123456789");

        // double 출력
        Console.WriteLine("----- Double Output -----");
        PrintDouble(d1);
        PrintDouble(d2);
        PrintDouble(d3);
        PrintDouble(d4);
        PrintDouble(d5);
        PrintDouble(d6);
        PrintDouble(d7);
        PrintDouble(d8);

        // double 출력 (앞에 10자리만)
        Console.WriteLine("----- Double Output (Trunc) -----");
        PrintDoubleTrunc(d1);
        PrintDoubleTrunc(d2);
        PrintDoubleTrunc(d3);
        PrintDoubleTrunc(d4);
        PrintDoubleTrunc(d5);
        PrintDoubleTrunc(d6);
        PrintDoubleTrunc(d7);
        PrintDoubleTrunc(d8);

        // decimal 출력
        Console.WriteLine("----- Decimal Output -----");
        PrintDecimal(dec1);
        PrintDecimal(dec2);

        // BigInteger 출력
        Console.WriteLine("----- BigInteger Output -----");
        PrintBigInteger(big1);
        PrintBigInteger(big2);
        PrintBigInteger(big3);
    }

    // Double 출력 함수
    static void PrintDouble(double n)
    {
        // 단위 배열
        string[] units = { "", "만", "억", "조", "경", "해", "자", "양", "구", "간",
                          "정", "재", "극", "항하사", "아승기", "나유타", "불가사의", "무량대수" };

        // 단위별 4자리값 저장 리스트
        List<int> parts = new List<int>();

        // 기준값
        double tmp = 10000.0;

        // 4자리씩 잘라서 parts에 저장
        while (n > 0 && parts.Count < units.Length)
        {
            // 하위 4자리 추출
            parts.Add((int)(n % tmp));
            // 만 단위 나누기
            n /= tmp;
        }

        // 큰 단위부터 출력
        for (int i = parts.Count - 1; i >= 0; i--)
        {
            if (parts[i] > 0)
                Console.Write($"{parts[i]}{units[i]} ");
        }
        Console.WriteLine();
    }

    // Double 출력 함수 (10자리까지만)
    static void PrintDoubleTrunc(double n)
    {
        // 단위 배열
        string[] units = { "", "만", "억", "조", "경", "해", "자", "양", "구", "간",
                        "정", "재", "극", "항하사", "아승기", "나유타", "불가사의", "무량대수" };

        // 지수표기 제거 문자열 변환
        string s = n.ToString("0");

        // 앞 10자리만 남기고, 나머지는 0으로 채움 (뒤 버림)
        if (s.Length > 10)
        {
            string first10 = s.Substring(0, 10);
            s = first10 + new string('0', s.Length - 10);
        }

        // 오른쪽에서 4자리씩 끊어 단위 부여
        List<string> parts = new List<string>();
        // 문자열 끝을 가리키는 인덱스
        int idx = s.Length;
        // 단위 배열의 인덱스
        int unitIndex = 0;

        // 오른쪽부터 4자리씩 잘라 단위 붙이기
        while (idx > 0 && unitIndex < units.Length)
        {
            // 잘라낼 문자 개수, 앞쪽에 1~3일 수 있기에 Min()
            int slice = Math.Min(4, idx);

            // 잘라낼 구간 떼기
            idx -= slice;
            string group = s.Substring(idx, slice);

            // 4자리 수, 0이 아닐시 단위 붙혀서 저장
            int val = int.Parse(group);
            if (val != 0)
                parts.Add($"{val}{units[unitIndex]}");

            // 단위 배열 인덱스 증가
            unitIndex++;
        }
        // 큰 단위부터 문자열 출력
        parts.Reverse();
        Console.WriteLine(string.Join(" ", parts));
    }


    // Decimal 출력 함수
    static void PrintDecimal(decimal n)
    {
        // 단위 배열
        string[] units = { "", "만", "억", "조", "경", "해", "자", "양", "구", "간",
                          "정", "재", "극", "항하사", "아승기", "나유타", "불가사의", "무량대수" };

        // 단위별 4자리값 저장 리스트
        List<int> parts = new List<int>();
        // 기준값
        decimal tmp = 10000m;

        // 4자리씩 잘라서 parts에 저장
        while (n > 0 && parts.Count < units.Length)
        {
            // 하위 4자리 추출
            parts.Add((int)(n % tmp));
            // 만 단위 나누기
            n /= tmp;
        }

        // 큰 단위부터 출력
        for (int i = parts.Count - 1; i >= 0; i--)
        {
            if (parts[i] > 0)
                Console.Write($"{parts[i]}{units[i]} ");
        }
        Console.WriteLine();
    }

    // BigInteger 출력 함수
    static void PrintBigInteger(BigInteger n)
    {
        // 단위 배열
        string[] units = { "", "만", "억", "조", "경", "해", "자", "양", "구", "간",
                          "정", "재", "극", "항하사", "아승기", "나유타", "불가사의", "무량대수" };

        // 단위별 4자리값 저장 리스트
        List<int> parts = new List<int>();
        // 기준값
        BigInteger tmp = 10000;

        // 4자리씩 잘라서 parts에 저장
        while (n > 0 && parts.Count < units.Length)
        {
            // 하위 4자리 추출
            parts.Add((int)(n % tmp));
            // 만 단위 나누기
            n /= tmp;
        }

        // 큰 단위부터 출력
        for (int i = parts.Count - 1; i >= 0; i--)
        {
            if (parts[i] > 0)
                Console.Write($"{parts[i]}{units[i]} ");
        }
        Console.WriteLine();
    }
}
