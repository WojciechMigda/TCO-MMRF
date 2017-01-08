#!/opt/anaconda2/bin/python
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 31 23:16:55 2016

@author: wojtek
"""

from __future__ import print_function

def main():
    import numpy as np
    xavg = np.genfromtxt('../../data/expressions_example.csv', delimiter=',', dtype=float, skip_header=1)
    xdiff = np.genfromtxt('../../data/copynumber_example.csv', delimiter=',', dtype=float, skip_header=1)
    mut = np.genfromtxt('../../data/mutations_example.csv', delimiter=',', dtype=float, skip_header=1)
    prog_obs = np.genfromtxt('../../data/groundtruth_example.csv', delimiter=',', dtype=float, skip_header=1)

    xarr = []
    yarr = []
    for i in range(prog_obs.shape[0]):
        if np.isnan(prog_obs[i][0]):
            continue
        #print(type(prog_obs[i]))
        xarr.append(np.concatenate([xavg[i], xdiff[i], mut[i]]))
        yarr.append(prog_obs[i][0])
        pass
    X = np.array(xarr)
    y = np.array(yarr)
    print(X.shape)
    print(y.shape)

    import xgboost as xgb
    clf = xgb.XGBRegressor(n_estimators=10000,
                           learning_rate=0.04)
    clf.fit(X, y)

    fis = clf.booster().get_fscore()
    ranked_fis = sorted(((v, k) for k, v in fis.iteritems()), reverse=True)
    for f, val in ranked_fis:
        print(f, val)

    return

if __name__ == "__main__":
    main()
