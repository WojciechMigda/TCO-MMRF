#!/opt/anaconda2/bin/python
# -*- coding: utf-8 -*-

"""
################################################################################
#
#  Copyright (c) 2016 Wojciech Migda
#  All rights reserved
#  Distributed under the terms of the MIT license
#
################################################################################
#
#  Filename: mmrf_hyperopt.py
#
#  Decription:
#      MMRF model parameter optimization
#
#  Authors:
#       Wojciech Migda
#
################################################################################
#
#  History:
#  --------
#  Date         Who  Ticket     Description
#  ----------   ---  ---------  ------------------------------------------------
#  2016-12-28   wm              Initial version
#
################################################################################
"""

from __future__ import print_function


DEBUG = False

__all__ = []
__version__ = "0.0.1"
__date__ = '2016-12-28'
__updated__ = '2016-12-28'


def work():
    def objective(space):
        cmd = './main ' + \
              '--xgboost_params=on ' + \
              '--booster=gblinear ' + \
              '--learning_rate=0.045 ' + \
              '--n_estimators={} ' + \
              '--reg_lambda={} ' + \
              '--reg_alpha={} ' + \
              '--reg_lambda_bias={} ' + \
              ''
        cmd = cmd.format(
                int(space['n_estimators']),
                space['reg_lambda'],
                space['reg_alpha'],
                space['reg_lambda_bias']
                )

        acc = 0.

        jobs = [cmd + ' --seed={}'.format(i) for i in range(3)]

        import subprocess
        import shlex
        processes = []
        for job in jobs:
            print("Running: " + job)
            p = subprocess.Popen(shlex.split(job),
                                 stdout=subprocess.PIPE,
                                 stderr=subprocess.PIPE,
                                 cwd='..')
            processes.append(p)
        for p in processes:
            stdout,stderr = p.communicate()
            print(stderr)
            score = float(stdout)
            print("Score: {}".format(score))
            acc += score

        acc = acc / len(jobs)
        #print(space)
        print("Avg score: {} , {}".format(acc, space))
        return -acc


    from sys import path as sys_path
    sys_path.insert(0, './hyperopt')
    from hyperopt import fmin, tpe, hp

    # cheatsheet:
    # https://github.com/hyperopt/hyperopt/wiki/FMin#21-parameter-expressions
    space = {
        'n_estimators': hp.quniform("x_n_estimators", 10, 80, 5),
        'reg_lambda': hp.uniform ('x_reg_lambda', 0.0, 10.0),
        'reg_alpha': hp.uniform ('x_reg_alpha', 0.0, 10.0),
        'reg_lambda_bias': hp.uniform ('x_reg_lambda_bias', 0.0, 10.0),
        #'learning_rate': hp.uniform ('x_learning_rate', 0.03, 0.06),
        }
    best = fmin(fn=objective,
        space=space,
        algo=tpe.suggest,
        #max_evals=500,
        max_evals=300,
        )
    print(best)
    return


def main(argv=None): # IGNORE:C0111
    '''Command line options.'''
    from sys import argv as Argv

    if argv is None:
        argv = Argv
        pass
    else:
        Argv.extend(argv)
        pass

    from os.path import basename
    program_name = basename(Argv[0])
    program_version = "v%s" % __version__
    program_build_date = str(__updated__)
    program_version_message = '%%(prog)s %s (%s)' % (program_version, program_build_date)
    try:
        program_shortdesc = __import__('__main__').__doc__.split("\n")[1]
    except:
        program_shortdesc = __import__('__main__').__doc__
    program_license = '''%s

  Created by Wojciech Migda on %s.
  Copyright 2016 Wojciech Migda. All rights reserved.

  Licensed under the MIT License

  Distributed on an "AS IS" basis without warranties
  or conditions of any kind, either express or implied.

USAGE
''' % (program_shortdesc, str(__date__))

    try:
        from argparse import ArgumentParser
        from argparse import RawDescriptionHelpFormatter
        from argparse import FileType
        from sys import stdout

        # Setup argument parser
        parser = ArgumentParser(description=program_license, formatter_class=RawDescriptionHelpFormatter)

#        parser.add_argument("-n", "--num-est",
#            type=int, default=700, action='store', dest="nest",
#            help="number of Random Forest estimators")
#
#        parser.add_argument("-j", "--jobs",
#            type=int, default=-1, action='store', dest="njobs",
#            help="number of jobs")
#
#        parser.add_argument("-f", "--cv-fold",
#            type=int, default=5, action='store', dest="nfolds",
#            help="number of cross-validation folds")
#
#        parser.add_argument("--clf-params",
#            type=str, default="{}", action='store', dest="clf_params",
#            help="classifier parameters subset to override defaults")
#
#        parser.add_argument("-G", "--cv-grid",
#            type=str, default="{}", action='store', dest="cv_grid",
#            help="cross-validation grid params (used if NFOLDS > 0)")
#
#        parser.add_argument("-E", "--estimator",
#            action='store', dest="estimator", default='XGBClassifier',
#            type=str,# choices=['mean', 'median', 'most_frequent'],
#            help="Estimator class to use")
#
#        parser.add_argument("-H", "--hyperopt",
#            action='store_true', dest="do_hyperopt",
#            help="Do hyperopt exploration")


        # Process arguments
        args = parser.parse_args()

        for k, v in args.__dict__.items():
            print(str(k) + ' => ' + str(v))
            pass

        work()

        return 0
    except KeyboardInterrupt:
        ### handle keyboard interrupt ###
        return 0
    except Exception as e:
        if DEBUG:
            raise(e)
            pass
        indent = len(program_name) * " "
        from sys import stderr
        stderr.write(program_name + ": " + repr(e) + "\n")
        stderr.write(indent + "  for help use --help")
        return 2

    pass


if __name__ == "__main__":
    if DEBUG:
        from sys import argv
        argv.append("-n 700")
        pass
    from sys import exit as Exit
    Exit(main())
    pass
