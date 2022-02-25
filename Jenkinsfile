pipeline{
  agent{
    label "PlatformIO"
  }
  stages{
    stage("Build"){
      steps{
        dir("ExhaustControl") {
          sh("pio run -v")
        }
      }
    }
  }
  post{
    always{
      sh("pio system prune --force")
    }
    success{
      echo "========pipeline executed successfully ========"
    }
    failure{
      echo "========pipeline execution failed========"
    }
  }
}