#!/usr/bin/python3

import pandas

import subprocess

exec_path = "./cmake-build-debug/main"
labels = ["Optimal", "LRU", "MRU", "Marking", "RR", "LFU", "ULT"]


def test(test_type: str, configs: list):
    ress = []

    for c in configs:
        args = [str(e) for e in c]
        args.insert(0, test_type)
        args.insert(0, exec_path)

        proc = subprocess.run(args, capture_output=True)
        res = proc.stdout.rstrip().split()
        res = list(map(float, res))
        ress.append(res)

    return ress


def test_loop():
    configs = [
        [128, 16, 128, 2400],
        [128, 24, 128, 2400],
        [128, 32, 128, 4800],
        [128, 48, 128, 7500],
        [128, 64, 128, 10000],
        [128, 96, 96, 10000],
        [128, 128, 64, 10000],
        [128, 192, 48, 10000],
        [128, 256, 32, 10000],
    ]

    results = test("loop", configs)

    dataset = dict()
    index = []
    for label in labels:
        dataset[label] = []

    for (config, result) in tuple(zip(configs, results)):
        res_with_label = tuple(zip(labels, result))
        for (cache_type, missed_ratio) in res_with_label:
            dataset[cache_type].append(1.0 - missed_ratio)
        index.append(config[1])

    return dataset, index

if __name__ == "__main__":
    import matplotlib.pyplot as plt

    dataset, index = test_loop()
    df = pandas.DataFrame(dataset, index=index)
    print(df)
    df.plot.line()

    plt.show()
